#include <stdio.h>

// a ultima vez que fiz um quicksort, foi no primeiro periodo, mas como eu sei a logica ainda, vou tentar escrever, não sei se irei conseguir mas isso vai subir por git, eu fazendo certo ou não.

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


int main(){

    int x=2, y=3;
    printf("%d, %d\n", x, y);
    troca(&x,&y);
    printf("%d, %d\n", x, y);


    return 0;
}