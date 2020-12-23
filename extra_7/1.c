#include <stdio.h>

int isInRange(int number, int low, int high){
    if (low > high)
        return 0;
    
    if (number >= low && number <= high)
        return 1;
    
    return 0;
}


int main(){
    int a = 65535;
    printf("%d is in range? %d\n", a, isInRange(a, 55, 65536));
    return 0;
}