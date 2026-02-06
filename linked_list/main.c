#include <stdio.h>
#include <stdlib.h>

typedef struct Block{
    int value;
    struct Block* next;
}Block;

Block* newBlock(int value){
    Block* b = malloc(sizeof(Block));
    if(!b)
        return NULL;
    
    b->value = value;
    b->next = NULL;
    return b;
}

int addnewBlock(Block* b, int value){
    if(!b)
        return 0;
    
    while(b->next != NULL){
        b = b->next;
    }

    b->next = newBlock(value);

    return 1;
}

int popFirst(Block** first, int* outValue){
    //pegamos um ponteiro de uma ponteiro do bloco
    //criamos uma variavel temp, e colocamos o pronteiro do bloco nela 
    //agora vamos trocar o ponteiro do bloco para o do proximo
    //e por fim liberar o first antigo
    if(!first || !*first)
        return 0;

    Block* tmp = *first;

    if(outValue)
        *outValue = tmp->value;

    *first = tmp->next;
    free(tmp);

    return 1;
}

int popLast(Block* b, int* outValue){
    if(!b)
        return 0;

    if(!b->next){
        printf("Lista com um item só!");
        return 0;
    }
    //vamos verificar se o next do proximo é nulo
    Block* next = b->next;
    while(next->next != NULL){
        b= b->next;
        next= b->next;
    }

    if(outValue)
        *outValue = next->value;

    b->next = NULL;
    free(next);
    return 1;
}

int main(){
    printf("Start\n");

    Block* b = newBlock(5);
    
    addnewBlock(b, 4);
    addnewBlock(b, 3);
    addnewBlock(b, 2);
    addnewBlock(b, 1);
    popLast(b, NULL);


    while(b != NULL){
        printf("%d\n", b->value);
        b = b->next;
    }

    printf("end");

    return 0;
}