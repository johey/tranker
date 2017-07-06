#include "list.h"

#include <stdio.h>

list_t *list_init() {
    list_t *list = (list_t *)malloc(sizeof(list_t));
    node_t *first = (node_t *)malloc(sizeof(node_t));
    node_t *last = (node_t *)malloc(sizeof(node_t));
    first->next = last;
    last->prev = first;
    first->prev = NULL;
    last->next = NULL;
    list->first = first;
    list->last = last;

    return list;
}

void list_destruct(list_t *list) {
    free(list->first);
    free(list->last);
    list->first = list->last = NULL;
    free(list);
}

// Push last in list
void list_push(list_t *list, node_t *node) {
    node->prev = list->last->prev;
    node->next = list->last;
    list->last->prev->next = node;
    list->last->prev = node;
}

// Pop first in list
node_t *list_pop(list_t *list) {
    node_t *node;
    if (list->first->next == list->last) return NULL;
    node = list->first->next;
    list->first->next = node->next;
    list->first->next->prev = list->first;
    return node;
}

