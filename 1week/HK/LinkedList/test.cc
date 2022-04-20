#include "../../../gtest/include/gtest/gtest.h"
#include "linkedlist.h"
#include <stdio.h>

TEST(create, must_success) { EXPECT_NE(createLinkedList(), nullptr); };
TEST(create, initial_check) {
    EXPECT_EQ(createLinkedList()->currentElementCount, 0);
    EXPECT_EQ(createLinkedList()->headerNode.pLink, nullptr);
    EXPECT_EQ(createLinkedList()->headerNode.data, 0);
};
TEST(add, zero_index_empty_list) {
    LinkedList *list = createLinkedList();
    ListNode element;
    int position = 0;

    element.data = 1;
    element.pLink = nullptr;

    EXPECT_EQ(addLLElement(list, position, element), position);
}

TEST(add, zero_index_not_empty_list) {
    LinkedList *list = createLinkedList();
    ListNode element;
    int position = 0;
    element.data = 1;
    element.pLink = nullptr;

    addLLElement(list, 0, element);
    EXPECT_EQ(addLLElement(list, position, element), position);
}

TEST(add, overflow_index_empty_list) {
    LinkedList *list = createLinkedList();
    ListNode element;
    int position = 1;

    element.data = 1;
    element.pLink = nullptr;

    EXPECT_EQ(addLLElement(list, position, element), -1);
};

TEST(get, zero_index_empty_list) {
    LinkedList *list = createLinkedList();

    EXPECT_EQ(getLLElement(list, 0), nullptr);
};

TEST(get, zero_index_not_empty_list) {
    LinkedList *list = createLinkedList();
    ListNode element;
    int position = 0;
    element.data = 1;
    element.pLink = nullptr;
    addLLElement(list, 0, element);

    EXPECT_NE(getLLElement(list, 0), nullptr);
};

TEST(get, print_single_element) {
    LinkedList *list = createLinkedList();
    ListNode element;
    int position = 0;
    element.data = 1;
    element.pLink = nullptr;
    addLLElement(list, 0, element);

    EXPECT_EQ(getLLElement(list, 0)->data, 1);
};

TEST(get, print_elements) {
    LinkedList *list = createLinkedList();
    ListNode element;
    int position = 0;

    element.data = 2;
    element.pLink = nullptr;
    addLLElement(list, 0, element);
    element.data = 1;
    addLLElement(list, 0, element);
    element.data = 0;
    addLLElement(list, 0, element);

    for (int i = 0; i < 3; ++i)
        EXPECT_EQ(getLLElement(list, i)->data, i);
};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}