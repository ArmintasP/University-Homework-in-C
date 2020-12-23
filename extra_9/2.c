#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int capacity;
    int *ptr;
};

typedef struct Stack Stack;

void initStack(Stack *stack){
    stack->capacity = 0;
    stack->ptr = NULL;
}

void printStack(Stack *stack){
    if (stack->ptr == NULL){
        printf("Stack is empty!\n");
        return ;
    }
    for (int i = 0; i < stack->capacity; ++i){
        printf("%d ", *(stack->ptr+i));
    }
    printf("\n");
}

int getStackSize(Stack *stack){
    return stack->capacity;
}

void push(Stack *stack, int value){
    int size = ++(stack->capacity);
    stack->ptr = realloc(stack->ptr, size * sizeof(int));
    *(stack->ptr + (stack->capacity - 1)) = value;
}

int top(Stack *stack){
    if (stack->ptr == NULL){
        return 0;
    }
    return *(stack->ptr + stack->capacity - 1);
}

int pop(Stack *stack){
    int value = top(stack);
    if (stack->ptr == NULL){
        return value;
    }
    int size = --(stack->capacity);
    stack->ptr = realloc(stack->ptr, size * sizeof(int));
    return value;
}

void destroyStack(Stack *stack){
    for(int i = 0; i < stack->capacity; ++i){
        *(stack->ptr + i) = 0;
    }
    if (stack->ptr != NULL){
        free(stack->ptr);
        stack->ptr = NULL;
    }
    stack->capacity = 0;
}

int main(){

    Stack s;
    initStack(&s);
    push(&s, 5);
    push(&s, 8);
    printf("Capacity: %d.\n", getStackSize(&s));
    printStack(&s);
    push(&s, 12);

    printf("Top element: %d.\n", top(&s));
    printStack(&s);
    pop(&s);
    printStack(&s);

    destroyStack(&s);
    printStack(&s);

    return 0;
}