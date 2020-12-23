#include <stdio.h>


void swap(int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main(){
    int a = 10, b = 55;
    printf("Before swap: %d & %d\n", a, b);
    swap(&a, &b);

    printf("After swap: %d & %d\n", a, b);

    return 0;
}