#include "LinkedList.h"


void test(struct LinkedList* list);
void test_get_index(struct LinkedList* list);
void test_sort(struct LinkedList* list);


int main() {
    struct LinkedList* list = NewLinkedList(500);
    //test(list);
    test_get_index(list);
    //test_sort(list);
    LinkedList_dump(list);
    DestroyLinkedList(list);
    return 0;
}



void test_sort(struct LinkedList* list) {
    LinkedListSort(list);
    LinkedListPopFront(list);
    LinkedListPopFront(list);
    LinkedListPushBack(list, 1000);
    LinkedListPushFront(list, 2000);
    printf("%lf\n", LinkedListGetIthLogical(list, 3));
    //LinkedListPushFront(list, 4000);
    if (list->sorted) {
        printf("Oh! List is still sorted\n");
    } else {
        printf("List is not sorted now\n");
    }
}

void test_get_index(struct LinkedList* list) {
    LinkedListPushBack(list, 0.1); // log 0
    LinkedListPushBack(list, 0.2); // log 1
    LinkedListPushBack(list, 0.3); // log 2
    LinkedListPushBack(list, 0.4); // log 3
    LinkedListPushBack(list, 0.5); // log 4
    size_t physical_ind = LinkedListGetPhysicalIndex(list, 3);
    LinkedListPushAfterPhysI(list, -10, physical_ind);
    LinkedListPushAfterPhysI(list, 10, physical_ind);
    LinkedListPushBeforePhysI(list, -20, physical_ind);
    LinkedListPushBeforePhysI(list, 20, physical_ind);
    //LinkedListPopFront(list);
}

void test(struct LinkedList* list) {
    LinkedListPushBack(list, 1);
    LinkedListPushBack(list, 2);
    LinkedListPushBack(list, 3);
    LinkedListPushFront(list, 4);
    LinkedListPushFront(list, 5);
    LinkedListPopBack(list);
    LinkedListPushBack(list, 6);
    LinkedListPopFront(list);
}
