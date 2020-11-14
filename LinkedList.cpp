#include "LinkedList.h"

#ifdef _DEBUG
    #define ASSERT_OK {if (LinkedList_ok(list) != LISTOK) {LinkedList_dump(list); assert(!"OK");}}
#else
    #define ASSERT_OK
#endif

#define INSERT_EMPTY                                       \
    size_t push_index = list->first_free;                  \
    list->first_free = list->array[list->first_free].next; \
    list->array[push_index].next = 0;                      \
    list->array[push_index].prev = 0;                      \
    list->array[push_index].value = value;                 \
    list->head = push_index;                              \
    list->tail = push_index;                               \
    list->size++;

struct LinkedList* LinkedList_construct(size_t capacity) {
    assert(capacity > 0);
    struct LinkedList* list = (struct LinkedList*)calloc(1, sizeof(struct LinkedList));
    list->array = (struct Node*)calloc(capacity, sizeof(struct Node));
    list->capacity = capacity;
    list->first_free = 1;
    list->size = 0;
    for (size_t i = 0; i < capacity; ++i) {
        list->array[i].value = NAN;
        if (i < capacity - 1 && i > 0) {
            list->array[i].next = i + 1;
        }
    }
    ASSERT_OK

    return list;
}

Elem_t LinkedList_get_physical_index(struct LinkedList* list, size_t index) {
    assert(list);
    assert(0 <= index && index < list->size);

    ASSERT_OK

    printf("WARNING! GETTING PHYSICAL INDEX IS SLOW OPERATION!!1!\n");
    size_t phys_i = list->head;
    size_t cnt = index;
    while (cnt > 0) {
        cnt--;
        phys_i = list->array[phys_i].next;
    }
    return phys_i;

    ASSERT_OK
}

Elem_t LinkedList_get_i(struct LinkedList* list, size_t index) {
    assert(list);
    assert(0 <= index && index < list->size);

    ASSERT_OK

    return list->array[index].value;
}

Elem_t LinkedList_get_front(struct LinkedList* list) {
    return LinkedList_get_i(list, list->head);
}

Elem_t LinkedList_get_back(struct LinkedList* list) {
    return LinkedList_get_i(list, list->tail);
}

void LinkedList_push_back(struct LinkedList* list, Elem_t value) {
    if (list->size == 0) {
        INSERT_EMPTY
    } else {
        LinkedList_push_after_i(list, value, list->tail);
    }
}

void LinkedList_push_front(struct LinkedList* list, Elem_t value) {
    if (list->size == 0) {
        INSERT_EMPTY
    } else {
        LinkedList_push_before_i(list, value, list->head);
    }
}

void LinkedList_pop_back(struct LinkedList* list) {
    LinkedList_pop_physical_i(list, list->tail);
}

void LinkedList_pop_front(struct LinkedList* list) {
    LinkedList_pop_physical_i(list, list->head);
}

void LinkedList_push_after_i(struct LinkedList* list, Elem_t value, size_t index) {
    assert(list);
    assert(list->size > 0);
    assert(!isnan(list->array[index].value));

    ASSERT_OK
    if (list->sorted && index == list->tail) {
        /*it is still sorted*/
    } else {
        list->sorted = false;
    }

    struct Node* array = list->array;

    size_t place_to_insert = list->first_free;
    list->first_free = list->array[list->first_free].next;

    array[place_to_insert].value = value;
    array[place_to_insert].next  = list->array[index].next;
    array[place_to_insert].prev  = index;
    array[index].next            = place_to_insert;

    size_t right = array[place_to_insert].next;
    if (right != 0) {
        array[right].prev = place_to_insert;
    } else {
        list->tail = place_to_insert;
    }
    list->size++;

    ASSERT_OK
}

void LinkedList_push_before_i(struct LinkedList* list, Elem_t value, size_t index) {
    assert(list);
    assert(list->size > 0);
    assert(!isnan(list->array[index].value));

    ASSERT_OK

    if (list->sorted && index == list->head && list->head > 1) {
        /*it is still sorted*/
    } else {
        list->sorted = false;
    }

    struct Node* array = list->array;

    size_t place_to_insert = list->first_free;
    list->first_free = list->array[list->first_free].next;

    array[place_to_insert].value = value;
    array[place_to_insert].next  = index;
    array[place_to_insert].prev  = list->array[index].prev;
    array[index].prev            = place_to_insert;

    size_t left = array[place_to_insert].prev;
    if (left != 0) {
        array[left].next = place_to_insert;
    } else {
        list->head = place_to_insert;
    }
    list->size++;

    ASSERT_OK

}

void LinkedList_pop_physical_i(struct LinkedList* list, size_t pop_i) {
    assert(list);
    assert(!isnan(list->array[pop_i].value));

    ASSERT_OK

    list->sorted = false;

    struct Node* array = list->array;

    size_t left_i = array[pop_i].prev;
    size_t right_i = array[pop_i].next;
    if (left_i != 0) {
        array[left_i].next = right_i;
    } else {
        list->head = right_i;
    }

    if (right_i != 0) {
        array[right_i].prev = left_i;
    } else {
        list->tail = left_i;
    }

    array[pop_i].value = NAN;
    array[pop_i].prev  = 0;
    array[pop_i].next  = list->first_free;

    list->first_free = pop_i;
    list->size--;

    ASSERT_OK

}

int LinkedList_ok(struct LinkedList* list) {
    assert(list);

    if (list->size < 0) {
        return SIZEERROR;
    }

    if (list->capacity <= 0 || list->size > list->capacity) {
        return CAPACITYERROR;
    }

    if (list->array == NULL) {
        return ARRAYPOINTERERROR;
    }

    size_t cur_ind = list->head;

    for (size_t i = 0; i < list->size; ++i) {
        if (cur_ind == 0) {
            return INDEXERRORS;
        }
        if (i == list->size - 1 && cur_ind != list->tail) {
            return LASTINDEXERROR;
        }
        cur_ind = list->array[cur_ind].next;
        if (i == list->size - 1 && cur_ind != 0) {
            return INDEXERRORS;
        }
    }

    for (size_t i = 0; i < list->capacity; ++i) {
        if (isnan(list->array[i].value) && list->array[i].prev != 0) {
            return POISONHASPREVERROR;
        }
    }
    return LISTOK;
}

void LinkedList_dump(struct LinkedList* list) {
    FILE* output = fopen("listdump.txt", "w");
    assert(output);

    #define DEF_ERROR(error, number)              \
        if (result == number) {                   \
            fprintf(output, " (%s) {\n", #error); \
        } else


    fprintf(output, "LinkedList [%p]", list);
    int result = LinkedList_ok(list);
    #include "errors.h"
    /*else*/ printf("(error number %d) {\n", result);
    #undef DEF_ERROR

    fprintf(output, "\tcapacity   = %-4zu\n", list->capacity);
    fprintf(output, "\tsize       = %-4zu\n", list->size);
    fprintf(output, "\tfirst_free = %-4zu\n", list->first_free);
    fprintf(output, "\tfirst      = %-4zu\n", list->head);
    fprintf(output, "\tlast       = %-4zu\n", list->tail);
    fprintf(output, "\tarray [%p] {\n", list->array);
    for (size_t i = 0; i < list->capacity; ++i) {
        // size_t last_elem = list->array[cur_elem].prev;
        // size_t next_elem = list->array[cur_elem].next;
        // cur_elem = i;
        // printf("i am %zu, last is %zu, next is %zu\n", i, last_elem, next_elem);
        fprintf(output, "\t\t[%-3zu] = {next: %-4zu | prev: %-4zu | value: %lf}\n", i, list->array[i].next, list->array[i].prev, list->array[i].value);
    }
    fprintf(output, "\t}\n}");
    fclose(output);

    LinkedList_make_graph(list);
}


void LinkedList_make_graph(struct LinkedList* list) {
    assert(list);

    const char* start_str = "digraph structs {\n\trankdir=HR;\n";
    FILE* output = fopen("graph.txt", "w");
    assert(output);
    fprintf(output, start_str);
    size_t cur_elem = list->head;
    struct Node* array = list->array;
    for (size_t i = 0; i < list->capacity; ++i) {
        // if (cur_elem == 0) {
        //     break;
        // }
        //fprintf(output, "\tel%-8zu [shape=record,label=\"{{pos:\\n %zu | ind:\\n %zu} | { <f1>prev:\\n %zu | value:\\n %lf | <f2> next:\\n %zu}}\"];\n", cur_elem, i, cur_elem, last_elem, array[cur_elem].value, next_elem);
        cur_elem = i;
        size_t last_elem = array[cur_elem].prev;
        size_t next_elem = array[cur_elem].next;
        fprintf(output, "\tel%-8zu [shape=record,label=\"{{<f0> phys pos:\\n %zu} | { <f1>prev:\\n %zu | value:\\n %lf | <f2> next:\\n %zu}}\"", i, i, last_elem, array[cur_elem].value, next_elem);
        if (isnan(array[cur_elem].value)) {
            fprintf(output, "style=filled,color=\"red\"]\n");
        } else {
            fprintf(output, "]\n");
        }
        if (i < list->capacity - 1) {
            fprintf(output, "el%-8zu ->el%-8zu [style=invis]", i, i + 1);
        }
        //cur_elem = array[cur_elem].next;
    }
    cur_elem = list->head;
    for (size_t i = 0; i < list->capacity; ++i) {
        // if (cur_elem == 0) {
        //     break;
        // }
        cur_elem = i;
        size_t last_elem = array[cur_elem].prev;
        size_t next_elem = array[cur_elem].next;
        if (next_elem != 0) {
            fprintf(output, "\tel%-8zu:<f2> -> el%-8zu:<f0> [color=\"red\"];\n", cur_elem, next_elem);
        }
        if (last_elem != 0) {
            fprintf(output, "\tel%-8zu:<f1> -> el%-8zu:<f0> [color=\"blue\"];\n", cur_elem, last_elem);
        }
        cur_elem = array[cur_elem].next;
    }
    fprintf(output, "}");
    fclose(output);
    //system("dot -Tsvg graph.txt > img.svg");
}

void LinkedList_sort(struct LinkedList* list) {
    assert(list);

    ASSERT_OK

    struct Node* new_array = (struct Node*)calloc(list->capacity, sizeof(struct Node));
    assert(new_array);
    size_t cur_ind = list->head;
    new_array[0].value = NAN;
    for (size_t i = 0; i < list->size; ++i) {
        new_array[i + 1].value = list->array[cur_ind].value;
        new_array[i + 1].prev = i;
        new_array[i + 1].next = i + 2;
        cur_ind = list->array[cur_ind].next;
    }
    for (size_t i = list->size + 1; i < list->capacity; ++i) {
        new_array[i].next = i + 1;
        new_array[i].value = NAN;
    }
    new_array[list->size].next = 0;
    free(list->array);
    list->array = new_array;
    list->first_free = list->size + 1;
    list->head = 1;
    list->tail = list->size;

    list->sorted = true;

    ASSERT_OK
}

Elem_t LinkedList_get_i_sorted(struct LinkedList* list, size_t index) {
    assert(list);
    assert(index < list->size);
    assert(list->sorted);

    ASSERT_OK

    return list->array[index + 1].value;
}
