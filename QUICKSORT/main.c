#include <stdio.h>

// a ultima vez que fiz um quicksort, foi no primeiro periodo, mas como eu sei a logica ainda, vou tentar escrever, não sei se irei conseguir mas isso vai subir por git, eu fazendo certo ou não.

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int lista[], int inicio, int fim){
    int indicePivo = fim;
    int i = inicio -1;
    int j = inicio;

    while(j < fim){
        if(lista[j]< lista[indicePivo]){
            i++;
            troca(&lista[j], &lista[i]);
        }
        j++;
    }
    i++;
    troca(&lista[i], &lista[indicePivo]);
    return i;

}

void quicksort(int lista[], int inicio, int fim){
    if(inicio < fim){
        int indicePivo = particionar(lista, inicio, fim);
        quicksort(lista, inicio, indicePivo-1);
        quicksort(lista, indicePivo+1, fim);
    }
}




int main(){

    int x=2, y=3;
    printf("%d, %d\n", x, y);
    troca(&x,&y);
    printf("%d, %d\n", x, y);

    int list[] = {4 ,8, 9, 9, 9, 3, 2, 5};
    for(int i=0; i<8 ; i++){
        printf("%d ", list[i]);
    }
    printf("\n");

    quicksort(list, 0, 7);

    for(int i=0; i<8 ; i++){
        printf("%d ", list[i]);
    }
    printf("\n");


    return 0;
}