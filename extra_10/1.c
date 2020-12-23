#include <stdio.h>
#include <assert.h>

int s_strlen(char * str){
    int i;
    for (i = 0; *(str + i) != '\0'; ++i)
        ;
    return i;
}


int main(){
    assert(s_strlen("hello\0") == 5);
    assert(s_strlen("\0") == 0);
    assert(s_strlen("fin\0") == 3);
    return 0;
}