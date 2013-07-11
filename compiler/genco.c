//genco

//#include "astree.h"
//#include "hash.h"
#include "tac.h"

static int count=0;

TAC *generateCode(AST* node)
{
    TAC *list;
    TAC *list_rev;
    
    list = genCode(node);
    
    fprintf(stderr, "\nrevertendo...");
    list_rev = tac_reverse(list);
    fprintf(stderr, "\nreverteu...\n\n");
    
    tac_print_all(list_rev);

    return list_rev;
}

TAC* genCode(AST* node)
{
    int i;
    TAC *code[4];
    TAC *result=0;
    
    for (i=0; i<4; i++)
        code[i] = 0;
    
    if (!node) {
        fprintf(stderr, "retornando...\n");
        return 0;
    }
    
    // process recurs...
    for (i=0; i<4; i++)
    {
        if (node->children[i])
            code[i] = genCode(node->children[i]);
    }
    
    // process one
    
    fprintf(stderr, "\nprocessando um...\n");
    //astPrint(node,0);
    astPrintNode(node);fprintf(stderr, "processou...%d\n", count++);
    
    switch (node->type) {
        case AST_DEC_VAR:
            fprintf(stderr, "AST_DEC_VAR...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_create(TAC_VAR,node->symbol,(code[1] ? code[1]->target:0),(code[2] ? code[2]->target:0));
            break;
        case AST_DEC_VET:
            fprintf(stderr, "AST_DEC_VET...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_create(TAC_VET,node->symbol,(code[1] ? code[1]->target:0),0);
            break;
        case AST_VET_SIZE:
            fprintf(stderr, "AST_VET_SIZE...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_create(TAC_VET_SIZE,node->symbol,0,0);
            break;
        case AST_LIST_VAL:
            fprintf(stderr, "AST_LIST_VAL...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_create(TAC_LIST_VAL,node->children[0]->symbol,0,0);
            fprintf(stderr, "AST_LIST_VAL\n");
            break;
        case AST_SYMBOL_LIT:
            fprintf(stderr, "AST_SYMBOL_LIT...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_create(TAC_SYMBOL_LIT,node->symbol,0,0);
            fprintf(stderr, "AST_SYMBOL_LIT\n");
            break;
        case AST_SYMBOL:fprintf(stderr, "AST_SYMBOL...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_create(TAC_SYMBOL,node->symbol,0,0);
            fprintf(stderr, "AST_SYMBOL\n");
            break;
         /*   
        case AST_DEC_VET:fprintf(stderr, "AST_SYMBOL...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_create(TAC_SYMBOL,node->symbol,0,0);
            fprintf(stderr, "AST_SYMBOL\n");
            break;*/
            
        case AST_SUM: fprintf(stderr, "AST_SUM...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_binary_operation(code[0], code[1], TAC_SUM);
            fprintf(stderr, "AST_SUM\n");
            break;
        case AST_SUB: fprintf(stderr, "AST_SUB...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_binary_operation(code[0], code[1], TAC_SUB);
            fprintf(stderr, "AST_SUB\n");
            break;
        case AST_MUL: fprintf(stderr, "AST_MUL...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_binary_operation(code[0], code[1], TAC_MUL);
            fprintf(stderr, "AST_MUL\n");
            break;
        case AST_DIV: fprintf(stderr, "AST_DIV...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_binary_operation(code[0], code[1], TAC_DIV);
            fprintf(stderr, "AST_DIV\n");
            break;
        
        case AST_EQ: fprintf(stderr, "AST_EQ...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_binary_operation(code[0], code[1], TAC_EQ);
            break;
		case AST_NE: fprintf(stderr, "AST_NE...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_binary_operation(code[0], code[1], TAC_NE);
            break;
		case AST_GE: fprintf(stderr, "AST_GE...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_binary_operation(code[0], code[1], TAC_GE);
            break;
		case AST_LE: fprintf(stderr, "AST_LE...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_binary_operation(code[0], code[1], TAC_LE);
            break;
		case AST_GT: fprintf(stderr, "AST_GT...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_binary_operation(code[0], code[1], TAC_GT);
            break;
		case AST_LT: fprintf(stderr, "AST_LT...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_binary_operation(code[0], code[1], TAC_LT);
            break;
        
        case AST_AND: fprintf(stderr, "AST_AND...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_binary_operation(code[0], code[1], TAC_AND);
            break;
		case AST_OR: fprintf(stderr, "AST_OR...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_binary_operation(code[0], code[1], TAC_OR);
            break;
            
        case AST_ATR: fprintf(stderr, "AST_ATR...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_join(code[0], tac_create(TAC_MOV, node->symbol, code[0] ? code[0]->target : 0, 0));fprintf(stderr, "AST_ATR\n");
            break;

        case AST_DEC_FUN:fprintf(stderr, "AST_DEC_FUN...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_join(tac_create(TAC_BEGINFUN, node->symbol, 0,0),
                              tac_join(code[3], tac_create(TAC_ENDFUN, node->symbol, 0, 0)));
            break;
            
        case AST_RETURN:fprintf(stderr, "AST_RETURN...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_join(code[0], tac_create(TAC_RETURN, (code[0] ? code[0]->target : 0), 0, 0));
            break;
            
        case AST_OUTPUT:fprintf(stderr, "AST_OUTPUT...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_join(code[0], tac_create(TAC_OUTPUT, (code[0] ? code[0]->target : 0), 0, 0));
            break;
            
        case AST_INPUT:fprintf(stderr, "AST_INPUT...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_create(TAC_INPUT, (code[0] ? code[0]->target : 0), 0, 0);
            break;
            
        case AST_IF: fprintf(stderr, "AST_IF...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_if_then(code[0], code[1], code[2]);fprintf(stderr, "AST_IF\n");
            break;

        case AST_LOOP: fprintf(stderr, "AST_LOOP...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = make_loop(code[0], code[1]);
            break;
            
        case AST_VET: //acesso vetor
            fprintf(stderr, "AST_VET...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_join(code[0], 
                              tac_create(TAC_ACCESS_VET, make_temp(), 
                                         node->symbol, 
                                         node->children[0]->symbol)
                              );
            break;
            
        case AST_CALL:
        case AST_CALL_EMPTY: 
            fprintf(stderr, "AST_CALL_EMPTY...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_join(code[0], 
                              tac_create(TAC_FUN_CALL, make_temp(), node->symbol, 0));
            break;
            
        case AST_ATR_VET: fprintf(stderr, "AST_ATR_VET...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_join(code[1], 
                              tac_join(code[0], 
                                       tac_create(TAC_ATR_VET, 
                                                  node->symbol,
                                                  code[0] ? code[0]->target : 0, 
                                                  code[1] ? code[1]->target : 0)
                                       )
                              );
            break;
            
        //--------------------------------------- up ok
            
        // mais/menos/outros nodos aqui talvez seja preciso...
        case AST_LIST_PARAM_SEP:
        case AST_LIST_PARAM:
        case AST_PAREN:
        case AST_COMMAND:
        case AST_BLOCO:
        case AST_LIST_DEC:
        case AST_LIST_COM:
        case AST_LIST_COM_SEP:
        case AST_DEC_LOC_VAR:
		case AST_DEC: 
            fprintf(stderr, "VARIOS CASOS...nodtyp %d\n", node->type);print_vectCode(code[0],code[1],code[2],code[3]);
            result = tac_join(code[0], code[1]);fprintf(stderr, "VARIOS CASOS\n");
            break;
            
            
            
        //loop ****************
            
        default:fprintf(stderr, "default...\n");print_vectCode(code[0],code[1],code[2],code[3]);
            result = 0;fprintf(stderr, "default type %d\n", node->type);
            // tac_join(tac_join(tac_join(code[0], code[1]), code[2]), code[3]);
            break;
    }
    
    //debug
    //tac_print_list
    fprintf(stderr, "tac result return\n");
    tac_print_all_reverse(result);
    
    return result;
}

TAC* make_binary_operation(TAC *code0, TAC *code1, int opType)
{
    return tac_join(tac_join(code0, code1),
                    tac_create(opType, make_temp(), code0?code0->target:0, code1?code1->target:0));
}

TAC* make_loop(TAC *code0, TAC *code1) {
    HASH_NODE *labelCode = make_label();
    HASH_NODE *labelCheck = make_label();
    TAC *jmpToCode;
    TAC *jmpToCheck;
    TAC *lblCode;
    TAC *lblCheck;
    lblCode = tac_create(TAC_LABEL, labelCode, 0, 0);
    lblCheck = tac_create(TAC_LABEL, labelCheck, 0, 0);
    jmpToCheck = tac_create(TAC_JUMP, labelCheck, 0, 0); 
    jmpToCode = tac_create(TAC_JZ, labelCode, code0 ? code0->target:0, 0);

    return tac_join(jmpToCheck, tac_join(lblCode, tac_join(code1, tac_join(lblCheck, tac_join(code0, jmpToCode)))));
}

// cond, then, else
TAC* make_if_then(TAC *code0, TAC *code1, TAC *code2)
{
    TAC *jmpIf;
    TAC *lblElse;
    HASH_NODE *labelElse = make_label();
    
    jmpIf = tac_create(TAC_JZ, labelElse, code0 ? code0->target : 0, 0);
    lblElse = tac_create(TAC_LABEL, labelElse, 0, 0);
    
    // else vazio, só if then
    if (!code2) {
        return tac_join(
                        tac_join(
                                 tac_join(code0, jmpIf), 
                                 code1), 
                        lblElse);
        
    // tem else, if then else
    } else {
        HASH_NODE *labelFim = make_label();
        
        // pula o else se caiu no then
        TAC *jmpIncond = tac_create(TAC_JUMP, labelFim, 0, 0);
        
        TAC *lblFim = tac_create(TAC_LABEL, labelFim, 0, 0);
        
        return tac_join(
                        tac_join(
                                 tac_join(
                                          tac_join(
                                                   tac_join(
                                                            tac_join(code0, jmpIf), 
                                                            code1), 
                                                   jmpIncond),
                                          lblElse),
                                 code2),
                        lblFim);
    }
}

void print_vectCode(TAC* code0,TAC* code1,TAC* code2,TAC* code3)
{
    tac_print_all(code0);
    tac_print_all(code1);
    tac_print_all(code2);
    tac_print_all(code3);
}

// comentarios da aula

// tac->last no ultimo parametro do for da tac_print_list
// while eh igual ao if then, apenas com o um jump absoluto no fim do then










