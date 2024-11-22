#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"


int function(int count, ...)
{
    int s = 0;
    int i;
    int x = 0;
    va_list ar;
    va_start(ar, count);
    for (i = 0; i < count; i++){
        x = va_arg(ar, int);

        s += x;
    }
    va_end(ar);
    return (s);
}
int main()
{
   printf("%d\n",ft_printf("%d%d%d%d", 1, 2,3 , 20));
}