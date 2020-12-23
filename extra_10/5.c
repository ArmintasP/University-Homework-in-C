#include <stdio.h>
#include <assert.h>

int s_memcmp(void *str1, void * str2, int num){
    char *temp1 = str1;
    char *temp2 = str2;

    while (num > 0){
        if (*temp1 != *temp2){
            return *temp1 - *temp2;
        }
        else{
            ++temp1;
            ++temp2;
            --num;
        }
    }

    return 0;
}

int main(){

    char *a = "Mister";
    char *b = "Mistress";
    assert(s_memcmp("", "a", 0) == 0);
    assert(s_memcmp("ss", "sz", 1) == 0);
    assert(s_memcmp(b, a, 0) == 0);
    assert(s_memcmp(a, b, 4) == 0);
    assert(s_memcmp(a, b, 5) < 0);
    assert(s_memcmp(b, a, 5) > 0);
    
    return 0;
}