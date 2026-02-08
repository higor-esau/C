#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* left;
    struct Node * right;
}No;

No* newNo(int value){
    No* n = malloc(sizeof(No));

    n->left = NULL;
    n->right = NULL;
    n->value = value;
    return n;
}

void addNoThree(No* no, int value){
    if(no->value == value){
        printf("Item já Existe!");
        return;
    }

    if(value < no->value){
        if(no->left == NULL){
            no->left = newNo(value);
            return;
        }
        addNoThree(no->left, value);
    }
    else{
        if(no->right == NULL){
            no->right = newNo(value);
            return;
        }
        addNoThree(no->right, value);
    }
}

void printInOrder(No* no){
    if(no == NULL)
        return;

    printInOrder(no->left);
    printf("%d ", no->value);
    printInOrder(no->right);
}



int main(){
    
    No* raiz = newNo(1);
    addNoThree(raiz, -1);
    addNoThree(raiz, 0);
    addNoThree(raiz, 5);
    addNoThree(raiz, 3);
    addNoThree(raiz, 3);

    return 0;
}