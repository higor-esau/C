#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int* base;
    int* end;
    int* sp;
}StackInt;


StackInt* newStack(int len){
    StackInt* stack = malloc(sizeof(StackInt));
    if(!stack)
        return NULL;
    
    stack->base = malloc(sizeof(int) * len);
    if(!stack->base)
        return NULL;

    stack->end = stack->base+len;
    stack->sp = stack->base;

    return stack;
}

int addNewValueStack(StackInt* stack, int value){
    if(stack->sp == stack->end)
        return 0;
    
    *stack->sp = value;
    stack->sp++;

    return 1;
}

int cadastrarNumero(StackInt* stack){
    printf("Digite o valor a ser cadastrado:\n");
    int input;

    while (!scanf("%d", &input))
        printf("Digite um valor inteiro!\n");
    
    return addNewValueStack(stack, input);
}

int pop(StackInt* stack){
    if(stack->base == stack->sp){
        printf("Stack sem itens\n");
        return 0;
    }
    stack->sp--;
    return 1;
}

int estaNaLista(int* list, int len, int value){
    if(len == 0)
        return 0;
    
    for(int i=0 ; i<len ; i++){
        if(*list == value)
            return 1;
        list++;
    }
    return 0;
}

void mostrarNumerosPares(StackInt* stack){
    int* start = stack->base;
    int* sp = stack->sp;

    if(start == sp ){
        printf("Stack sem itens!\n");
        return;
    }

    while(start < sp){
        if(*start %2 == 0){
            printf("%d -> ", *start);
        }
        start++;
        }
        
    printf("\n");
}

int Menu(){
    StackInt* stack = newStack(20);
    while(1){
        printf("1- Cadastrar numero\n");
        printf("2- Mostrar numeros pares\n");
        printf("3- Excluir numero\n");
        printf("4- Sair\n");
        int input;
        while (!scanf("%d", &input))
            printf("Digite um valor inteiro!\n");
        

        switch (input)
        {
        case 1:
            cadastrarNumero(stack);
            break;
        case 2:
            mostrarNumerosPares(stack);
            break;
        case 3:
            if(pop(stack)){
                printf("Remoção bem sucedida!\n");
            }
            break;
        case 4:
            return 1 ;
            break;
        
        default:
            printf("Opção invalida!\n");
            break;
        }
    }
}


int main(){
    
    Menu();


    return 0;
}