#include "libmx.h"

void mx_del_arr_matrix_int(int ***arr) {
    int ***p;
    int **pp;

    if (arr == NULL)
        return;
    p = arr;
    pp = *arr;
    while (**p != NULL) {
        mx_del_matrix_int(*p);
        (*p)++;
    }
    free(pp);
    *arr = NULL;
}
