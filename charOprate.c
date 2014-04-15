#include <stdio.h>
//×Ö·û´®²Ù×÷
void swap_char(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char *a, int s, int d)
{
    while (s < d)
    {
        swap_char(&a[s], &a[d]);
        s++;
        d--;
    }
}
