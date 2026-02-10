void printStack(Stack* stack){
    int value=0, i=0;
    while(pop(stack, &value)){
        printf("%d: %d\n", i, value);
        i++;
    }
    printf("End Stack!\n");
}