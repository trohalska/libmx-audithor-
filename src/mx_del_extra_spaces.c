#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *s;
    char *rez;

    if (!str)
        return NULL;
    s = mx_strnew(mx_strlen(str));
    if (s)
        for (int k = 0; *str; s[k++] = *(str++))
            if (mx_isspace(*str)){
                for (s[k++] = ' '; mx_isspace(*str); ++str);
                if (!(*str))
                    break;
            }
    rez = mx_strtrim(s);
    free(s);
    return rez;
}
