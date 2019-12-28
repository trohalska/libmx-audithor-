#include "libmx.h"

static int count_value(const char *hex, int i);

unsigned long mx_hex_to_nbr(const char *hex) {
    unsigned long result = 0;
    int value;
    unsigned long pow_sixteen;

    if (!hex || *hex == 0)
        return result;
    for (int i = 0; i < mx_strlen(hex); i++) {
        value = count_value(hex, i);
        pow_sixteen = 1;
        for (int j = 0; j < mx_strlen(hex) - i - 1; j++)
            pow_sixteen *= 16;
        result += value * pow_sixteen;
        hex++;
    }
    return result;
}

static int count_value(const char *hex, int i) {
    int t;

    if (hex[i] >= '0' && hex[i] <= '9')
        t = hex[i] - '0';
    else if (hex[i] >= 'a' && hex[i] <= 'f')
        t = hex[i] - 'a' + 10;
    else if (hex[i] >= 'A' && hex[i] <= 'F')
        t = hex[i] - 'A' + 10;
    else
        exit(0);
    return t;
}
