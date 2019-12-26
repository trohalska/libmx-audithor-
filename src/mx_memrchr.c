#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n){
    const unsigned char *str;
    unsigned char x = (unsigned char)c;

    if (n == 0)
        return NULL;
    str = (const unsigned char *)s + n - 1;
    for (; (--n > 0) && (*str != x); str--);
    return (*str == x) ? (void *)str : NULL;
}
