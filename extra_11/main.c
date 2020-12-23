#include "file.h"
#include <time.h>

void fillArray(int *array, int size, int low, int high)
{
    if (low > high)
    {
        int temp = low;
        low = high;
        high = temp;
    }
    srand(time(NULL));
    for (int i = 0; i < size; ++i)
    {
        array[i] = rand() % (high - low + 1) + low;
    }
}

void printArray(int *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int size = 12;
    int *m1 = malloc(sizeof(int) * size);
    int *m2 = malloc(sizeof(int) * size);
    int *m3 = malloc(sizeof(int) * size);
    fillArray(m1, size, 0, 8);
    fillArray(m2, size, 5, 12);
    fillArray(m3, size, 0, 12);

    printf("m1 saved to file:\n");
    printArray(m1, size);
    saveToFile(m1, size, "my.bin");
    printf("m3 saved to file:\n");
    printArray(m3, size);
    saveToFile(m3, size, "my.bin");
    int new_size;
    loadFromFile(&m1, &new_size, "my.bin");
    printf("m1 from file:\n");
    printArray(m1, new_size);

    printf("m2 saved to file2:\n");
    printArray(m2, size);
    saveToFile(m2, size, "my2.bin");

    loadFromFile(&m3, &new_size, "my2.bin");
    printf("m3 from file2:\n");
    printArray(m3, new_size);

    loadFromFile(&m2, &new_size, "my.bin");
    printf("m2 from file:\n");
    printArray(m2, new_size);

    if (saveCount == 3 && loadCount == 3)
    {
        printf("All good!\n");
    }
    else
    {
        printf("Something's wrong!\n");
    }

    return 0;
}