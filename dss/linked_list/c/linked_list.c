#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int key;
    struct node *next;
} node;

node* new_linked_list(const int *keys, size_t size) {
    node *list = NULL;
    node *last_node = NULL;
    for (int i = 0; i < size; i++) {
        node *new_node = malloc(sizeof(node));
        new_node->key = keys[i];
        new_node->next = NULL;
        if (last_node != NULL) {
            last_node->next = new_node;
        } else {
            list = new_node;
        }
        last_node = new_node;
    }
    return list;
}

// node* insert_at(node *list, int index, int key) {
//     return NULL;
// }

node* insert_first(node *list, int key) {
    if (list == NULL) {
        int keys[1] = {key};
        list = new_linked_list(keys, (size_t)1);
        return list;
    }
    node *new_node = malloc(sizeof(node));
    new_node->key = key;
    new_node->next=list;

    return new_node;
}

node* insert_last(node *list, int key) {
    if (list == NULL) {
        return NULL;
    }
    node *current_node = list;
    while (current_node->next != NULL) {
        current_node = current_node->next;
    }
    node *new_node = malloc(sizeof(node));
    new_node->key = key;
    new_node->next = NULL;
    current_node->next = new_node;
    return new_node;
}

node* get_node(node *list, int key) {
    node *current_node = list;
    while (current_node->next != NULL && current_node->key != key) {
        current_node = current_node->next;
    }
    if (current_node->key == key) {
        return current_node;
    }
    return NULL;
}

void delete_node(node *list, int key) {
    node *previous_node = NULL, *current_node = list;

    while (current_node != NULL && current_node->key != key) {
        previous_node = current_node;
        current_node = current_node->next;
    }
    if (current_node == NULL) {
        return;
    }
    previous_node->next = current_node->next;
    free(current_node);
}

void print_keys(node *list) {
    node *ptr = list;
    while (ptr != NULL) {
        printf("%d->", ptr->key);
        ptr = ptr->next;
    }
}

void free_list(node *list) {
    node *ptr = list;
    while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
}

int main(void) {
    int keys[5] = {1, 2, 3, 4, 5};
    node *list = NULL;
    list = insert_first(list, 100);
    print_keys(list);
    free_list(list);
}