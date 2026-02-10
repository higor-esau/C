#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Fila
{
    int init;
    int n;
    int vet[MAX];
}Fila;

Fila* newFila(){
    Fila* f = malloc(sizeof(Fila));
    f->init = 0;
    f->n = 0;
    return f;
}

int pushFila(Fila* f, int value){
    if(f->n == MAX)
        return 0;

    int fim = (f->init + f->n) %MAX;
    f->vet[fim] = value;
    f->n++;
    return 1;
}


int main(){


    return 0;
}