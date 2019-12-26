#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    char *s = (char *) haystack;
    int ln;

    if (!*needle)
        return s;
    ln = mx_strlen(needle);
    while (*s) {
        for (int i = 0; i < ln && s[i] == needle[i]; i++)
            if (needle[i + 1] == '\0')
                return s;
        s++;
    }
    return NULL;
}
