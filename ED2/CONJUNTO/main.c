#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int* base;
    int* end;
    int* sp;
}Stack;

Stack* newStack(int len){
    Stack* stack = malloc(sizeof(Stack));
    if(!stack)
        return NULL;

    stack->base = malloc(sizeof(int) * len);
    if(!stack->base)
        return NULL;

    stack->end = stack->base+len;
    stack->sp = stack->base;

    return stack;
}

int push(Stack* stack, int value){
    if(stack->sp == stack->end)
        return 0;

    *stack->sp = value;
    stack->sp = stack->sp +1;
    return 1;
}

int pop(Stack*  stack, int* outValue){
    if(stack->sp == stack->base)
        return 0;
    
    
    stack->sp = stack->sp - 1;
    *outValue = *stack->sp;
    return 1;
}

int popPrint(Stack*  stack){
    int x;
    pop(stack, &x);
    printf("%d", x);
}

void printStack(Stack* stack){
    int value=0, i=0;
    while(pop(stack, &value)){
        printf("%d: %d\n", i, value);
        i++;
    }
    printf("\nEnd Stack!\n");
}

void Questao(){
    Stack* stack = newStack(20);

    push(stack, 1);
    push(stack, 2);
    popPrint(stack);
    push(stack, 3);
    push(stack, 4);
    popPrint(stack);
    popPrint(stack);
    popPrint(stack);

    printStack(stack);
}
void QuestaoAA(){
    Stack* stack = newStack(20);
    int x;
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    popPrint(stack); //3
    popPrint(stack); // 2
    push(stack, 4);
    push(stack, 5);
    popPrint(stack); // 5
    push(stack, 6);
    popPrint(stack); // 6
    popPrint(stack); // 4
    popPrint(stack); // 1

}
void QuestaoAB(){
    Stack* stack = newStack(20);
    int x;
    push(stack, 1);
    popPrint(stack); 
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    popPrint(stack);
    popPrint(stack);
    push(stack, 6);
    popPrint(stack);
    popPrint(stack);
    popPrint(stack);

}


int main(){
    QuestaoAB();

    return 0;
}