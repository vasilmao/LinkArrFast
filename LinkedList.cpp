#include "LinkedList.h"



struct LinkedList* construct(size_t capacity) {
    assert(capacity > 0);
    struct LinkedList* list = (struct LinkedList*)calloc(1, sizeof(struct LinkedList));
    list->array = (struct Node*)calloc(capacity, sizeof(struct Node));
    list->capacity = capacity;
    list->first_free = 1;
    list->size = 0;
    for (size_t i = 1; i < capacity - 1; ++i) {
        list->array[i].next = i + 1;
    }
    return list;
}

void push_back(struct LinkedList* list, Elem_t value) {
    assert(list);
    size_t place_to_insert = list->first_free;
    list->first_free = list->array[list->first_free].next;
    list->array[place_to_insert].value = value;
    if (list->size > 0) {
        list->array[list->last].next = place_to_insert;
    }
    list->array[place_to_insert].prev = list->last;
    list->array[place_to_insert].next = 0;
    list->last = place_to_insert;
    if (list->size == 0) {
        list->first = place_to_insert;
    }

    list->size++;
}

void push_front(struct LinkedList* list, Elem_t value) {
    assert(list);
    size_t place_to_insert = list->first_free;
    list->first_free = list->array[list->first_free].next;
    list->array[place_to_insert].value = value;
    if (list->size > 0) {
        list->array[list->first].prev = place_to_insert;
    }
    list->array[place_to_insert].next = list->first;
    list->array[place_to_insert].prev = 0;
    list->first = place_to_insert;
    if (list->size == 0) {
        list->last = place_to_insert;
    }

    list->size++;
}

void pop_i(struct LinkedList* list, Elem_t value, size_t index) {
    assert(list);
    assert(index < list->size);
    assert(index >= 0);

    size_t pop_i = list->first;

    size_t cnt = index;
    while (cnt > 0) {
        cnt--;
        pop_i = list->array[last_i].next;
    }



}

void push_i(struct LinkedList* list, Elem_t value, size_t index) {
    assert(list);
    assert(index <= list->size);
    assert(index >= 0);
    size_t place_to_insert = list->first_free;
    list->first_free = list->array[list->first_free].next;
    list->array[place_to_insert].value = value;
    size_t last_i = list->first;
    size_t cnt = index;
    while (cnt > 0) {
        cnt--;
        last_i = list->array[last_i].next;
    }
    if (last_i == 0) {
        list->array[place_to_insert].next = 0;
        list->array[place_to_insert].prev = list->last;
        list->array[list->last].next = place_to_insert;
    } else if (list->array[last_i].prev == 0) {
        list->array[place_to_insert].prev = 0;
        list->array[place_to_insert].next = list->first;
        list->array[list->first].prev = place_to_insert;
    } else {
        size_t before_i = list->array[last_i].prev;
        list->array[place_to_insert].next = last_i;
        list->array[place_to_insert].prev = before_i;
        list->array[last_i].prev = place_to_insert;
        list->array[before_i].next = place_to_insert;
    }

    if (index == 0) {
        list->first = place_to_insert;
    }
    if (index == list->size) {
        list->last = place_to_insert;
    }
    printf("%zu\n", place_to_insert);
    printf("%lf\n", list->array[place_to_insert].value);
    printf("%zu\n", list->array[place_to_insert].next);
    printf("%zu\n", list->array[place_to_insert].prev);
    list->size++;

}

void pop_back(struct LinkedList* list) {
    assert(list);
    assert(list->size > 0);
    size_t ind = list->last;
    list->last = list->array[list->last].prev;
    list->array[list->last].next = 0;
    list->array[ind].next = list->first_free;
    list->first_free = ind;
    list->array[ind].prev = 0;
    list->array[ind].value = 0;

    list->size--;
}

void pop_front(struct LinkedList* list) {
    assert(list);
    assert(list->size > 0);
    size_t ind = list->first;
    list->first = list->array[list->first].next;
    list->array[list->first].prev = 0;
    list->array[ind].next = list->first_free;
    list->first_free = ind;
    list->array[ind].prev = 0;
    list->array[ind].value = 0;

    if (list->size == 1) {
        list->first = 0;
        list->last = 0;
    }

    list->size--;
}

void print_list(struct LinkedList* list) {
    assert(list);
    size_t ind = list->first;
    ind = list->first;
    for (size_t i = 0; i < list->size; ++i) {
        printf("%8zu ", ind);
        ind = list->array[ind].next;
    }
    printf("\n");
    ind = list->first;
    for (size_t i = 0; i < list->size; ++i) {
        printf("%lf ", list->array[ind].value);
        ind = list->array[ind].next;
    }
    printf("\n");
    ind = list->first;
    for (size_t i = 0; i < list->size; ++i) {
        printf("%8zu ", list->array[ind].next);
        ind = list->array[ind].next;
    }
    printf("\n");
    ind = list->first;
    for (size_t i = 0; i < list->size; ++i) {
        printf("%8zu ", list->array[ind].prev);
        ind = list->array[ind].next;
    }
    printf("\n");
}
