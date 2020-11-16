#include "LinkedList.h"


void test(struct LinkedList* list);
void test_get_index(struct LinkedList* list);
void test_sort(struct LinkedList* list);


int main() {
    struct LinkedList* list = LinkedList_construct(500);
    //test(list);
    test_get_index(list);
    test_sort(list);
    LinkedList_dump(list);
    return 0;
}



void test_sort(struct LinkedList* list) {
    LinkedList_sort(list);
    LinkedList_pop_front(list);
    LinkedList_pop_front(list);
    LinkedList_push_back(list, 1000);
    LinkedList_push_front(list, 2000);
    printf("%lf\n", LinkedList_get_i(list, 3));
    LinkedList_push_front(list, 3000);
    printf("%lf\n", LinkedList_get_i(list, 3));
    LinkedList_push_front(list, 4000);
    if (list->sorted) {
        printf("Oh! List is still sorted\n");
    } else {
        printf("List is not sorted now\n");
    }
}

void test_get_index(struct LinkedList* list) {
    LinkedList_push_back(list, 0.1); // log 0
    LinkedList_push_back(list, 0.2); // log 1
    LinkedList_push_back(list, 0.3); // log 2
    LinkedList_push_back(list, 0.4); // log 3
    LinkedList_push_back(list, 0.5); // log 4
    size_t physical_ind = LinkedList_get_physical_index(list, 4);
    LinkedList_push_after_i(list, -10, physical_ind);
    LinkedList_push_after_i(list, 10, physical_ind);
    LinkedList_push_before_i(list, -20, physical_ind);
    LinkedList_push_before_i(list, 20, physical_ind);
    LinkedList_pop_front(list);
}

void test(struct LinkedList* list) {
    LinkedList_push_back(list, 1);
    LinkedList_push_back(list, 2);
    LinkedList_push_back(list, 3);
    LinkedList_push_front(list, 4);
    LinkedList_push_front(list, 5);
    LinkedList_pop_back(list);
    LinkedList_push_back(list, 6);
    LinkedList_pop_front(list);
}
