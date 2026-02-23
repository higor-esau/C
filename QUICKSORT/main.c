#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int part(int list[], int start, int end){
    int indicePivo = end;
    int i = start -  1;
    for(int j = start ; j < end ; j++){
        if(list[j] < list[indicePivo]){
            i++;
            swap(&list[i], &list[j]);
        }
    }
    i++;
    swap(&list[i], &list[end]);
    return i;
}

void quicksort(int list[], int inicio, int end){
    if(inicio < end){
        int indice = part(list, inicio, end);
        quicksort(list, inicio, indice-1);
        quicksort(list, indice+1, end);
    }
}



int main(){

    int list[] = {12,2,9,54,626,-51,5,8,1,22,52,36,33,33,38,12,88888,100000};

    int len = sizeof(list) / sizeof(int);
    printf("\n\t%d\n", len);
    quicksort(list, 0, len -1);

    for(int i=0; i<len ; i++){
        printf("%d -> ", list[i]);
    }
    printf("\n");
    return 0;
}