#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

typedef double Elem_t;

#define DEF_ERROR(name, number) name = number,

enum ListErrors {
    #include "errors.h"
};

#undef DEF_ERROR

struct Node {
    size_t next;
    size_t prev;
    Elem_t value;
};

struct LinkedList {
    Node* array;
    size_t capacity;
    size_t first_free;
    size_t first;
    size_t last;
    size_t size;
};

struct LinkedList* construct (size_t capacity);
Elem_t list_get_i            (struct LinkedList* list, size_t index);
Elem_t list_get_front        (struct LinkedList* list);
Elem_t list_get_back         (struct LinkedList* list);
Elem_t get_physical_index    (struct LinkedList* list, size_t index);
void   list_push_back        (struct LinkedList* list, Elem_t value);
void   list_push_front       (struct LinkedList* list, Elem_t value);
void   push_after_i          (struct LinkedList* list, Elem_t value, size_t index);
void   push_before_i         (struct LinkedList* list, Elem_t value, size_t index);
void   list_pop_back         (struct LinkedList* list);
void   list_pop_front        (struct LinkedList* list);
void   pop_physical_i        (struct LinkedList* list, size_t pop_i);
void   list_make_graph       (struct LinkedList* list);
void   list_dump             (struct LinkedList* list);
int    list_ok               (struct LinkedList* list);
void   list_sort             (struct LinkedList* list);
Elem_t list_get_i_sorted     (struct LinkedList* list, size_t index);
void   pop_physical_i        (struct LinkedList* list, size_t pop_i);
