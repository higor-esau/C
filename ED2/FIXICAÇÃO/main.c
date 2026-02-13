#include <stdio.h>

void inverter(int *v, int len){
    if(len <= 0)
        return;

    inverter( v+1, len-1);
    printf("%d ", *v);
}

int contar(int *v, int len, int valor){
    if(len <= 0)
        return 0;

    if(valor == *v)
        return contar(v+1, len-1, valor) + 1;

    return contar(v+1, len-1, valor);
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int minha_strlen(char *str){
    printf("str -> ");
    if(*str == '\0')
        return 0;
    return minha_strlen(str+1) + 1;
}

int main(){

    int x[] = {1,2,3,2,5,2,7,2,9,2,11,2,13};
    int len = sizeof(x)/sizeof(int);
    inverter(x, len);
    printf("\nQuantidade: %d\n", contar(x, len, 1));
    char str[] = "higor";
    printf("\nQuantidade str: %d\n", minha_strlen(str));
    return 0;
}