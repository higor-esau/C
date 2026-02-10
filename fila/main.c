#include <stdio.h>
#include <stdlib.h>

typedef struct Block{
    int value;
    struct Block* prev;
    struct Block* next;
}Block;

typedef struct Queue{
    Block* first;
    Block* last;
    int quantity;
}Queue;


Block* newBlock(int value, Block* prev, Block* next){
    Block* b = malloc(sizeof(Block));
    if(!b)
        return NULL;

    b->value = value;
    b->prev = prev;
    b->next = next;
    return b;
}


// chat ajudou na logica do encurtar essa função, continua na mesmo ordem O(1)
int addBlockLastQueue(Queue* q, int value){
    if(!q)
        return 0;
    
    Block* b = newBlock(value, q->last, NULL);
    if(!b)
        return 0;

    
    if(q->first == NULL)
        q->first = b;
    else
        q->last->next = b;

    q->last = b;

    
    q->quantity++;
    return 1;
}

int addBlockFirstQueue(Queue* q, int value){
    if(!q)
        return 0;

    Block*b = newBlock(value, NULL, q->first);
    if(!b)
        return 0;

    if(q->first == NULL){
        q->last = b;
    }
    else
        q->first->prev = b;

    q->first = b;
    q->quantity++;
    return 1;
}

int popFirstQueue(Queue* q){
    if(!q || !q->first)
        return 0;
    
    Block* oldFirst  = q->first;

    if(oldFirst->next == NULL){
        free(oldFirst);
        q->first = NULL;
        q->last  = NULL;
        q->quantity = 0;
        return 1;
    }


    q->first = oldFirst->next;
    q->first->prev = NULL;

    free(oldFirst);
    q->quantity--;
    return 1;
}

int popLastQueue(Queue* q){
    if(!q || !q->last)
        return 0;

    Block* oldLast = q->last;

    if(oldLast->prev == NULL){
        free(oldLast);
        q->first = NULL;
        q->last = NULL;
        q->quantity = 0;
        return 1;
    }

    q->last = oldLast->prev;
    q->last->next = NULL;

    free(oldLast);
    q->quantity--;

    return 1;
}

void printQueueFirstToLast(const Queue* q){
    if(!q){
        printf("Queue NULL\n");
        return;
    }

    if(!q->first){
        printf("Queue vazia\n");
        return;
    }

    Block* current = q->first;

    printf("Queue (first -> last): ");

    while(current != NULL){
        printf("%d", current->value);

        if(current->next)
            printf(" -> ");

        current = current->next;
    }

    printf("\n");
}

Queue* initQueue(int value){
    Queue* q = calloc(1, sizeof(Queue));
    addBlockFirstQueue(q, value);
    return q;
}

int main(){

    Queue* q = initQueue(0);
    addBlockFirstQueue(q, 1);
    addBlockFirstQueue(q, 2);
    

    printQueueFirstToLast(q);

    return 0;
}