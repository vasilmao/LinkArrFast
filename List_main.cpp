#include "LinkedList.h"

void test(struct LinkedList* list) {
    list_push_back(list, 1);
    list_push_back(list, 2);
    list_push_back(list, 3);
    list_push_front(list, 4);
    list_push_front(list, 5);
    list_pop_back(list);
    list_push_back(list, 6);
    list_pop_front(list);
}

void test_get_index(struct LinkedList* list) {
    size_t physical_ind = get_physical_index(list, 2);
    push_after_i(list, -1, physical_ind);
    push_after_i(list, 1, physical_ind);
    push_before_i(list, -1, physical_ind);
    push_before_i(list, 1, physical_ind);
}

void test_sort(struct LinkedList* list) {
    list_sort(list);
    printf("%lf\n", list_get_i_sorted(list, 2));
}

int main() {
    struct LinkedList* list = construct(500);
    test(list);
    test_get_index(list);
    test_sort(list);
    list_dump(list);
    return 0;
}
