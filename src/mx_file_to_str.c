#include "libmx.h"

static int count_bytes_and_checks(const char *file);
static bool check(const char *file);

char *mx_file_to_str(const char *file) {
    char buf[1];
    int f;
    char *s;
    char *p;

    if (!check(file))
        return NULL;
    s = mx_strnew(count_bytes_and_checks(file));
    p = s;
    f = open(file, O_RDONLY);
    while (read(f, buf, sizeof(buf)) > 0) {
        *s = *buf;
        s++;
    }
    close(f);
    return p;
}

static int count_bytes_and_checks(const char *file) {
    char buf[1];
    int k = 0;
    int f = open(file, O_RDONLY);

    while (read(f, buf, sizeof(buf)) > 0)
        k++;
    close(f);
    return k;
}

static bool check(const char *file) {
    bool res = true;
    int f;
    int n;
    char buf[1];

    if (!file)
        res = false;
    f = open(file, O_RDONLY);
    if (f < 0)
        res = false;
    n = read(f, buf, sizeof(buf));
    if (n <= 0)
        res = false;
    close(f);
    return res;
}
