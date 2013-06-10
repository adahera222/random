#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include "uthash.h"

#define PORT 4000

typedef struct userLoginInfo{
    int usrSocket;
    char *login;
    char *name;
    UT_hash_handle hh;
} usrInfo;


// Read/Write lock to protect the access of user information.
pthread_rwlock_t usrHashLock;

#define lockWriteUserHash() \
    if (pthread_rwlock_wrlock(&usrHashLock) != 0) { \
         fprintf(stderr,"can't get wrlock"); \
         exit(-1); \
     } \

#define lockReadUserHash() \
    if (pthread_rwlock_rdlock(&usrHashLock) != 0) { \
         fprintf(stderr,"can't get wrlock"); \
         exit(-1); \
     } \

#define unlockUserHash() \
    pthread_rwlock_unlock(&usrHashLock);

// Maps username -> userInfo.
usrInfo *users;

#define addUser(i) \
     lockWriteUserHash(); \
     HASH_ADD_KEYPTR(hh, users, i->login, strlen(i->login), i ); \
     unlockUserHash();


#define rmvUser(i) \
     lockWriteUserHash(); \
     HASH_DEL(users, i); \
     unlockUserHash();

// puts found user in res
#define getUser(name, res) \
    lockReadUserHash(); \
    HASH_FIND_STR(users, name, res); \
    unlockUserHash(); \

time_t current_time;
struct tm * time_info;
char timestr[9];

int sendMsg(usrInfo *dest, char *msg) {
    int size = strlen(msg);
    if(size > 0) {
        if (write(dest->usrSocket,msg,size) < 0) 
            printf("ERROR: sending msg");
    }
}

void talkTo(char *dstName, char *msg, usrInfo *src) {
    // Search for destiny.
    usrInfo *dest;
    getUser(dstName, dest);
    
    if(dest) {
        sendMsg(dest, msg);
    } else {
        sendMsg(src,"|UNREACHABLE| :(\n");
    }
}

int handleMessageCommands(char *login, char *msg) {
    if (!strncmp(msg, "/nick", 5)) {
        usrInfo *target;
        getUser(login, target);
        strncpy(target->name, msg+6, strlen(msg));
        return 1;
    } else if (!strncmp(msg, "/list", 5)) {
        usrInfo *u;
        usrInfo *target;
        getUser(login, target);
        char user_list_msg[1024];
        strcpy(user_list_msg, "Connected users:\n");
        for(u=users; u != NULL; u=u->hh.next) {
            strcat(user_list_msg, u->login);
            strcat(user_list_msg, "\n");
        }
        sendMsg(target, user_list_msg);
        return 1;
    }
    return 0;
}

void broadcast(char *user, char *msg) {
    usrInfo *u;

    // Get current time and append it to broadcasted message
    time(&current_time);
    strftime(timestr, sizeof(timestr), "%H:%M:%S", localtime(&current_time));
    char user_msg[256];
    strcpy(user_msg, "[");
    strcat(user_msg, timestr);
    strcat(user_msg, "] ");

    // Append user so you can see who the message was sent from... 
    // If user == NULL then the message was sent from the server.
    if (user) {
        strcat(user_msg, user);
        strcat(user_msg, ": ");
    }
    strcat(user_msg, msg);

    // Send it to everyone!
    for(u=users; u != NULL; u=u->hh.next) {
        sendMsg(u, user_msg);
    }
}

void *handleUser(void *arg) {
    int n;
    char buffer[256];
    
    // Login.
    usrInfo *usr = (usrInfo *) arg;
    addUser(usr);
    
    // Tell everyone!
    printf("%s joined the server!\n", usr->name);
    strcpy(buffer, usr->name);
    strcat(buffer, " joined the server!");
    broadcast(NULL, buffer);
    
    // Receive messages.
    while(1) {
        bzero(buffer, 256);
    
        /* read from the socket */
        n = read(usr->usrSocket, buffer, 256);
        if (n < 0) 
		    printf("ERROR reading from socket\n");
		else
		    printf("%s RECEIVED\n", buffer);

        // Only broadcast if the message wasn't a command.
        if (!handleMessageCommands(usr->login, buffer)) broadcast(usr->name, buffer);
    }  
    // Logout.
    rmvUser(usr);
}

void *listenForUsers()
{
	int sockfd, newsockfd, n;
	socklen_t clilen;
	char buffer[256];
	
	// Initialize the socket receiver.
	struct sockaddr_in serv_addr, cli_addr;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
        printf("ERROR opening socket");
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(serv_addr.sin_zero), 8);     
    
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
		printf("ERROR on binding");
	
	listen(sockfd, 5);
	
	// Keep waiting for clients forever.
	while(1) {
	    
	     clilen = sizeof(struct sockaddr_in);
	     if ((newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen)) == -1) 
		    printf("ERROR on accept");
	
	    bzero(buffer, 256);
	    
	    /* read from the socket */
	    n = read(newsockfd, buffer, 256);
	    if (n < 0) 
		    printf("ERROR reading from socket");
		    
		// Keep user login info in structure.
		usrInfo *userLoginInfo = (usrInfo *) malloc(sizeof(usrInfo));
		userLoginInfo->usrSocket = newsockfd;
		userLoginInfo->login = (char *) malloc(sizeof(char)*256);
		userLoginInfo->name= (char *) malloc(sizeof(char)*256);
		strcpy(userLoginInfo->login, buffer);
		strcpy(userLoginInfo->name, buffer);
		
		// Create thread to handle user.
	    pthread_t *userThread = malloc(sizeof(pthread_t));
	    pthread_create(userThread, NULL, handleUser, userLoginInfo);
	    
	}
    close(newsockfd);
	close(sockfd);
	
}

int main(int argc, char *argv[])
{
    // Initialize user's Hash and it's lock.
    users = NULL;
    if (pthread_rwlock_init(&usrHashLock,NULL) != 0) {
        fprintf(stderr,"ERROR: creating user lock.");
        exit(-1);
    }

	listenForUsers();
	return 0; 
}
