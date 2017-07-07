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
    list->count = 0;

    return list;
}

void list_destruct(list_t *list) {
    free(list->first);
    free(list->last);
    list->first = list->last = NULL;
    free(list);
}

void list_push_back(list_t *list, void *data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->prev = list->last->prev;
    node->next = list->last;
    list->last->prev->next = node;
    list->last->prev = node;
    list->count++;
}

node_t *list_remove_at(list_t *list, uint8_t pos) {
    node_t *prev = list->first;
    node_t *node = prev->next;

    if (node == list->last) return NULL;

    for (uint8_t i = 0; i < pos; i++) {
        prev = node;
        if ((node = node->next) == (list->last)) return NULL;
    }
    prev->next = node->next;
    prev->next->prev = prev;

    list->count--;

    return node;
}

node_t *list_get_at(list_t *list, uint8_t pos) {
    node_t *node = list->first->next;

    for (uint8_t i = 0; i < pos; i++) {
        if ((node = node->next) == NULL) return NULL;
    }

    if (node == list->last) return NULL;

    return node;
}

uint8_t list_count(list_t *list) {
    return list->count;
}

