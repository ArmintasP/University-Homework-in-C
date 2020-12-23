#include <stdio.h>
#include <assert.h>


char *s_strcpy(char *dest, const char *src){
    int i;
    for (i = 0; src[i] != '\0'; ++i){
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

int main(){
    char a[50] = "Does this work?";
    char p[50] = "Random void filled with words";
  
    assert(*s_strcpy(p, a) == *a);
    char *b = "Will this work too?";
    assert(*s_strcpy(p, b) == *b);
    return 0;
}