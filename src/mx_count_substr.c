#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    char *s = (char *)str;;
    int ln;
    int k = 0;

    if (!str || !sub)
        return -1;
    ln = mx_strlen(sub);
    while (*s) {
        for (int i = 0; i < ln && s[i] == sub[i]; i++)
            if (sub[i + 1] == '\0')
                k++;
        s++;
    }
    return k;
}
