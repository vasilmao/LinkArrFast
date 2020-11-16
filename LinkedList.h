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
    size_t head;
    size_t tail;
    size_t size;
    bool sorted;
};

struct LinkedList* LinkedList_construct (size_t capacity);
Elem_t LinkedList_get_i            (struct LinkedList* list, size_t index);
Elem_t LinkedList_get_front        (struct LinkedList* list);
Elem_t LinkedList_get_back         (struct LinkedList* list);
Elem_t LinkedList_get_physical_index    (struct LinkedList* list, size_t index);
void   LinkedList_push_back        (struct LinkedList* list, Elem_t value);
void   LinkedList_push_front       (struct LinkedList* list, Elem_t value);
void   LinkedList_push_after_i          (struct LinkedList* list, Elem_t value, size_t index);
void   LinkedList_push_before_i         (struct LinkedList* list, Elem_t value, size_t index);
void   LinkedList_pop_back         (struct LinkedList* list);
void   LinkedList_pop_front        (struct LinkedList* list);
void   LinkedList_pop_physical_i        (struct LinkedList* list, size_t pop_i);
void   LinkedList_make_graph       (struct LinkedList* list);
void   LinkedList_dump             (struct LinkedList* list);
int    LinkedList_ok               (struct LinkedList* list);
void   LinkedList_sort             (struct LinkedList* list);
Elem_t LinkedList_get_i_sorted     (struct LinkedList* list, size_t index);
void   LinkedList_pop_physical_i        (struct LinkedList* list, size_t pop_i);
