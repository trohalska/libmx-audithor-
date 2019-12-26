#include "libmx.h"

int mx_sqrt(int x) {
    int i = 0;
    int j;
    int m;

    if (x < 0)
        return 0;
    j = x / 2 + 1;
    while (i <= j) {
        m = i + (j - i) / 2;
        if (m * m == x)
            return m;
        else if (m * m > x || m > 46340)
            j = m - 1;
        else
            i = m + 1;
    }
    return 0;
}
