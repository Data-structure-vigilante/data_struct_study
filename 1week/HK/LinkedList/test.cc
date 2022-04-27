#include "../../../gtest/include/gtest/gtest.h"
#include "linkedlist.h"
#include <stdio.h>

// testCaseName When_StateUnderTest_Expect_ExpectedBehavior

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

TEST(removeLLElement, when_emptyList_expect_minus1) {
    LinkedList *list = createLinkedList();

    EXPECT_EQ(removeLLElement(list, 0), -1);
}

TEST(removeLLElement, when_nullptr_expect_minus1) {
    EXPECT_EQ(removeLLElement(nullptr, 0), -1);
}

TEST(removeLLElement, when_oneElement_expect_position) {
    LinkedList *list = createLinkedList();
    ListNode element;

    element.data = 1;
    element.pLink = nullptr;

    addLLElement(list, 0, element);
    EXPECT_EQ(removeLLElement(list, 0), 0);
    EXPECT_EQ(list->currentElementCount, 0);
}

TEST(removeLLElement, when_ManyElementRemoveMiddlePosition_expect_position) {
    LinkedList *list = createLinkedList();
    ListNode element;

    element.pLink = nullptr;
    element.data = 0;
    addLLElement(list, 0, element);
    element.data = 1;
    addLLElement(list, 0, element);
    element.data = 2;
    addLLElement(list, 0, element);

    EXPECT_EQ(removeLLElement(list, 1), 1);
    EXPECT_EQ(list->currentElementCount, 2);
    EXPECT_EQ(list->headerNode.pLink->pLink->data, 0);
    EXPECT_EQ(list->headerNode.pLink->data, 2);
}

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

TEST(clear, clear_llist) {
    LinkedList *list = createLinkedList();
    ListNode element;

    element.data = 2;
    element.pLink = nullptr;
    addLLElement(list, 0, element);
    addLLElement(list, 0, element);
    addLLElement(list, 0, element);
    clearLinkedList(list);
    EXPECT_EQ(list->headerNode.pLink, nullptr);
    EXPECT_EQ(list->currentElementCount, 0);
}

TEST(getLinkedListLength, when_emptylist_expect_zero) {
    LinkedList *list = createLinkedList();

    EXPECT_EQ(getLinkedListLength(list), 0);
}

TEST(getLinkedListLength, when_threeElement_expect_zero) {
    LinkedList *list = createLinkedList();
    ListNode element;

    element.data = 2;
    element.pLink = nullptr;
    addLLElement(list, 0, element);
    addLLElement(list, 0, element);
    addLLElement(list, 0, element);
    EXPECT_EQ(getLinkedListLength(list), 3);
}

TEST(deleteLinkedList, when_emptyList_expect_notNullptr) {
    LinkedList *list = createLinkedList();

    deleteLinkedList(list);
    EXPECT_NE(list, nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}