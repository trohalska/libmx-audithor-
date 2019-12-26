#include "inc/libmx.h"

int main() {
    mx_printstr("\x1B[33m---mx_file_to_str---\x1B[0m\n");

    return 0;
}

// int main() {
//     mx_printstr("\x1B[33m---mx_file_to_str---\x1B[0m\n");
//     if (!mx_file_to_str("t.txt")) // if t.txt exists but empty
//         mx_printstr("NULL\n");
//     else {
//         mx_printstr(mx_file_to_str("t.txt")); // if there smth
//         mx_printstr("\n");
//     }
//     if (!mx_file_to_str(NULL)) // if t.txt exists but empty
//         mx_printstr("NULL\n");
//     return 0;
// }

// int main() {
//     mx_printstr("\x1B[31m---mx_count_substr---\x1B[0m\n");
//     mx_printint(mx_count_substr("yo yo yo kalg", "yo"));
//     mx_printstr("\n");
//     mx_printint(mx_count_substr("yo yo yooyyo kalg", "yo"));
//     mx_printstr("\n");
//     mx_printint(mx_count_substr(NULL, "yo"));
//     mx_printstr("\n");
//     mx_printint(mx_count_substr("yo yo yo kalg", NULL));
//     mx_printstr("\n");
//     mx_printint(mx_count_substr("", "yo"));
//     mx_printstr("\n");
//     mx_printint(mx_count_substr("yo yo yo kalg", ""));
//     mx_printstr("\n");
//     return 0;
// }
