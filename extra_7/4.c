#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generateArray(int data[], int size, int low, int high){
    
    if (low > high)
        return;

    srand(time(NULL));
    for (int i = 0; i < size; ++i)
        data[i] = rand() % (high - low + 1) + low;

}

int main(){
    
    int arr[50] = {0};
    
    generateArray(arr, 10, 1, 5);
    for (int i = 0; i < 50; ++i)
        printf("%d ", arr[i]);
    putchar('\n');

}