#include <stdio.h>

int getPositiveNumber(char *msg){
    int posnum;


    printf("%s", msg);
    while(scanf("%d", &posnum) != 1 || !(posnum > 0)){
        while (getchar() != '\n')
            ;
        printf("%s", msg);
    }

    return posnum;
}



int main(){

    char *msg = "Enter a positive number, mate.\n";
    int a = getPositiveNumber(msg);
    printf("My number is: %d\n", a);

    return 0;
}