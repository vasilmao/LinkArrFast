#include "LinkedList.h"

int main() {
    struct LinkedList* list = construct(500);
    push_back(list, 1);
    print_list(list);
    push_back(list, 2);
    print_list(list);
    push_back(list, 3);
    print_list(list);
    push_front(list, 4);
    print_list(list);
    pop_back(list);
    print_list(list);
    push_back(list, 5);
    print_list(list);
    pop_front(list);
    print_list(list);
    push_front(list, 6);
    print_list(list);
    push_back(list, 7);
    print_list(list);
    push_i(list, 8, 2);
    print_list(list);
    push_i(list, 9, 0);
    print_list(list);
    push_i(list, 10, 7);
    print_list(list);
    push_back(list, 11);
    print_list(list);
}
