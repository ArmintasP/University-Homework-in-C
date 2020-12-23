#include <stdio.h>

int getFactorial(int number){
    if (number == 1)
        return 1;
    if (number <= 0 || number > 16) // overflow įvyks, kai number > 16,
        return 0;
    
    return number * getFactorial(number - 1);
}

int getFactorialNotRecursive(int number){
    if (number <= 0 || number > 16) // overflow įvyks, kai number > 16,
        return 0;

    int i, factorial = 1;
    for(i = 1; i <= number; ++i)
        factorial *= i;

    return factorial;

}

int main(){
    int a = 16;
    printf("%d factorial? %d\n", a, getFactorialNotRecursive(a));
    return 0;
}