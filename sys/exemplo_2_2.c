#include <stdio.h>
#include <stdlib.h>

#define	TRUE 1


   while(TRUE) {
      printf("Thread %d iniciando a SC\n ", n);
      printf("Thread %d ainda na SC\n ", n);
      printf("Thread %d saindo da SC\n ", n);
      pthread_mutex_unlock(&m);
   int n1 = 1;
   int n2 = 2;