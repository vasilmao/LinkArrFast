#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef double Elem_t;

struct Node {
    Elem_t value;
    size_t next;
    size_t prev;
};

struct LinkedList {
    Node* array;
    size_t capacity;
    size_t first_free;
    size_t first;
    size_t last;
    size_t size;
};

struct LinkedList* construct(size_t capacity);
void push_back(struct LinkedList* list, Elem_t value);
void push_front(struct LinkedList* list, Elem_t value);
void pop_back(struct LinkedList* list);
void pop_front(struct LinkedList* list);
void print_list(struct LinkedList* list);
void push_i(struct LinkedList* list, Elem_t value, size_t index);
