#include "LinkedList.h"

int main() {
    struct LinkedList* list = construct(500);
    list_push_back(list, 1);
    list_push_back(list, 2);
    list_push_back(list, 3);
    list_push_front(list, 4);
    list_pop_back(list);
    list_push_back(list, 5);
    list_pop_front(list);
    list_push_front(list, 6);
    list_push_i(list, 8, 2);
    list_push_i(list, 9, 0);
    list_push_i(list, 10, 6);
    list_push_back(list, 11);
    list_pop_i(list, 2);
    list_sort(list);
    list_dump(list);
    return 0;
}
