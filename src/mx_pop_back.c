#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *p;

    if (!head || !(*head))
        return;
    if ((*head)->next == NULL) {  // if first is NULL-node
        (*head)->data = NULL;
        free(*head);
        *head = NULL;
        return;
    }
    else {
        p = *head;  // remember beginning
        while (p->next->next != NULL) // find last
            p = p->next;
        p->next->data = NULL;
        free(p->next);
        p->next = NULL;
    }
}
