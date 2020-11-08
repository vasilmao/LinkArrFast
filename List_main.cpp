#include "LinkedList.h"

int main() {
    struct LinkedList* list = construct(500);
    push_back(list, 1);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    push_back(list, 2);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    push_back(list, 3);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    push_front(list, 4);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    pop_back(list);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    push_back(list, 5);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    pop_front(list);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    push_front(list, 6);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    push_back(list, 7);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    push_i(list, 8, 2);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    push_i(list, 9, 0);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    push_i(list, 10, 7);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    push_back(list, 11);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    pop_i(list, 2);
    printf("%zu and %zu\n", list->first, list->last);
    print_list(list);
    make_graph(list);
}
