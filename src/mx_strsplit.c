#include "libmx.h"

static char **res_if_one_word(const char *s, int size);
static void res_if_more_words(const char *s, char c, char **res);

char **mx_strsplit(const char *s, char c) {
    int size;
    char **res;

    if (!s)
        return NULL;
    size = mx_count_words(s, c);
    res = res_if_one_word(s, size);
    if (size == 1)
        return res;
    res_if_more_words(s, c, res);
    // while (*s) {
    //     i_del = mx_get_char_index(s, c);
    //     i_del = i_del == -1 ? i_del = mx_strlen(s) : i_del;
    //     if (i_del) {
    //         res[i_res] = mx_strndup(s, i_del);
    //         s += mx_strlen(res[i_res]) - 1;
    //         i_res++;
    //     }
    //     s++;
    // }
    // res[i_res] = NULL;
    return res;
}

static char **res_if_one_word(const char *s, int size) {
    char **res = (char **) malloc((size + 1) * sizeof (char *));

    if (size == 1) {
        res[0] = mx_strdup(s);
        res[1] = NULL;
    }
    return res;
}

static void res_if_more_words(const char *s, char c, char **res) {
    int i_res = 0;
    int i_del = 0;

    while (*s) {
        i_del = mx_get_char_index(s, c);
        i_del = i_del == -1 ? i_del = mx_strlen(s) : i_del;
        if (i_del) {
            res[i_res] = mx_strndup(s, i_del);
            s += mx_strlen(res[i_res]) - 1;
            i_res++;
        }
        s++;
    }
    res[i_res] = NULL;
}
