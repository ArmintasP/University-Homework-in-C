#include <stdio.h>
#include <string.h>
#include <assert.h>

char *s_strncpy(char *dest, const char *src, int num)
{
    int i;
    for (i = 0; i < num; ++i)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}

int main(){

    char a[50];
    char b[50];
    char *c = "Make it work";
    assert(strcmp(s_strncpy(a, c, 0), "") == 0);
    assert(strcmp(s_strncpy(a, c, 5), "Make ") == 0);
    assert(strcmp(s_strncpy(a, "Works", 5), "Works") == 0);
    return 0;
}