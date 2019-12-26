#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int s = 0;

    if (!str)
        return -1; // in pdf needs to retern nothing?????
    while (*str != '\0') {
        if (*str == c)  // if not word
            while (*str == c && *str != '\0')
                str++;
        if (*str != c && *str != '\0') {  // if word
            s++;
            while (*str != c && *str != '\0')
                str++;
        }
    }
    return s;
}
