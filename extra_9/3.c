#include <stdio.h>
#include <stdlib.h>
#include <math.h>



struct Point
{
    double x;
    double y;
};
typedef struct Point Point;


struct Stack
{
    int capacity;
    Point *ptr;
};
typedef struct Stack Stack;

void printPoint(Point p)
{
    printf("(%.2f, %.2f)", p.x, p.y);
}

Point createPoint(double x, double y)
{
    Point p = {x, y};
    return p;
}

double getDistance(Point a, Point b)
{
    double x_part = (a.x - b.x) * (a.x - b.x);
    double y_part = (a.y - b.y) * (a.y - b.y);
    return sqrt((x_part + y_part));
}

void initStack(Stack *stack)
{
    stack->capacity = 0;
    stack->ptr = NULL;
}

void printStack(Stack *stack)
{
    if (stack->ptr == NULL)
    {
        printf("Stack is empty!\n");
        return;
    }
    for (int i = 0; i < stack->capacity; ++i)
    {
        printPoint(*(stack->ptr + i));
        printf(", l = %.2f.\n", getDistance(*(stack->ptr + i), createPoint(0, 0)));
    }
    printf("\n");
}

int getStackSize(Stack *stack)
{
    return stack->capacity;
}

void push(Stack *stack, Point value)
{
    int size = ++(stack->capacity);
    stack->ptr = realloc(stack->ptr, size * sizeof(Point));
    *(stack->ptr + (stack->capacity - 1)) = value;
}

Point top(Stack *stack)
{
    if (stack->ptr == NULL)
    {
        return createPoint(0, 0);
    }
    return *(stack->ptr + stack->capacity - 1);
}

Point pop(Stack *stack)
{
    Point value = top(stack);
    if (stack->ptr == NULL)
    {
        return value;
    }
    int size = --(stack->capacity);
    stack->ptr = realloc(stack->ptr, size * sizeof(Point));
    return value;
}

void destroyStack(Stack *stack)
{
    if (stack->ptr != NULL)
    {
        free(stack->ptr);
        stack->ptr = NULL;
    }
    stack->capacity = 0;
}

int main()
{

    Stack s;
    Point p1 = createPoint(3, 4);
    Point p2 = createPoint(4.5, -2.0);
    Point p3 = createPoint(8.00, 0.0);
    Point p4 = createPoint(1.00, 1.0);
    Point p5 = createPoint(10.00, 5.0);

    initStack(&s);
    push(&s, p1);
    push(&s, p2);
    printf("Capacity: %d.\n", getStackSize(&s));
    printStack(&s);
    push(&s, p3);

    printf("Top element: ");
    printPoint(top(&s));
    printf("\n");
    printStack(&s);

    pop(&s);

    push(&s, p4);
    push(&s, p5);

    printStack(&s);

    destroyStack(&s);
    printStack(&s);

    return 0;
}