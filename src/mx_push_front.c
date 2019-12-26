#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *tmp;

    if (!list || !data)
        return;
    tmp = mx_create_node(data);
    tmp->next = *list;
    *list = tmp;
}
