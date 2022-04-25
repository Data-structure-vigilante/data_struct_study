#include "../../../gtest/include/gtest/gtest.h"
#include "doublylist.h"
#include <stdio.h>

// testCaseName When_StateUnderTest_Expect_ExpectedBehavior

TEST(create, must_success) { EXPECT_NE(createDoublyList(), nullptr); };
TEST(create, initial_check) {
    DoublyList *list = createDoublyList();
    EXPECT_EQ(list->currentElementCount, 0);
    EXPECT_EQ(list->headerNode.pLLink, &list->headerNode);
    EXPECT_EQ(list->headerNode.pRLink, &list->headerNode);
    EXPECT_EQ(list->headerNode.data, 0);
};

TEST(add, zero_index_empty_list) {
    DoublyList *list = createDoublyList();
    DoublyListNode element;
    int position = 0;

    element.data = 1;
    element.pLLink = nullptr;
    element.pRLink = nullptr;

    EXPECT_EQ(addDLElement(list, position, element), position);
}

TEST(add, zero_index_not_empty_list) {
    DoublyList *list = createDoublyList();
    DoublyListNode element;
    int position = 0;
    element.data = 1;
    element.pRLink = nullptr;

    addDLElement(list, 0, element);
    EXPECT_EQ(addDLElement(list, position, element), position);
}

TEST(add, overflow_index_empty_list) {
    DoublyList *list = createDoublyList();
    DoublyListNode element;
    int position = 1;

    element.data = 1;
    element.pRLink = nullptr;

    EXPECT_EQ(addDLElement(list, position, element), -1);
};

TEST(add, index_list) {
    DoublyList *list = createDoublyList();
    DoublyListNode element;
    int position = 0;

    element.data = 1;
    element.pRLink = nullptr;
    addDLElement(list, position, element);
    addDLElement(list, position, element);
    addDLElement(list, position, element);

    position = 2;
    element.data = 3;
    EXPECT_EQ(addDLElement(list, position, element), 2);
    EXPECT_EQ(3, list->headerNode.pRLink->pRLink->pRLink->data);
};

// TEST(get, zero_index_empty_list) {
//     LinkedList *list = createLinkedList();

//     EXPECT_EQ(getLLElement(list, 0), nullptr);
// };

// TEST(get, zero_index_not_empty_list) {
//     LinkedList *list = createLinkedList();
//     ListNode element;
//     int position = 0;
//     element.data = 1;
//     element.pLink = nullptr;
//     addLLElement(list, 0, element);

//     EXPECT_NE(getLLElement(list, 0), nullptr);
// };

// TEST(get, print_single_element) {
//     LinkedList *list = createLinkedList();
//     ListNode element;
//     int position = 0;
//     element.data = 1;
//     element.pLink = nullptr;
//     addLLElement(list, 0, element);

//     EXPECT_EQ(getLLElement(list, 0)->data, 1);
// };

// TEST(get, print_elements) {
//     LinkedList *list = createLinkedList();
//     ListNode element;
//     int position = 0;

//     element.data = 2;
//     element.pLink = nullptr;
//     addLLElement(list, 0, element);
//     element.data = 1;
//     addLLElement(list, 0, element);
//     element.data = 0;
//     addLLElement(list, 0, element);

//     for (int i = 0; i < 3; ++i)
//         EXPECT_EQ(getLLElement(list, i)->data, i);
// };

// TEST(clear, clear_llist) {
//     LinkedList *list = createLinkedList();
//     ListNode element;

//     element.data = 2;
//     element.pLink = nullptr;
//     addLLElement(list, 0, element);
//     addLLElement(list, 0, element);
//     addLLElement(list, 0, element);
//     clearLinkedList(list);
//     EXPECT_EQ(list->headerNode.pLink, nullptr);
//     EXPECT_EQ(list->currentElementCount, 0);
// }

// TEST(getLinkedListLength, when_emptylist_expect_zero) {
//     LinkedList *list = createLinkedList();

//     EXPECT_EQ(getLinkedListLength(list), 0);
// }

// TEST(getLinkedListLength, when_threeElement_expect_zero) {
//     LinkedList *list = createLinkedList();
//     ListNode element;

//     element.data = 2;
//     element.pLink = nullptr;
//     addLLElement(list, 0, element);
//     addLLElement(list, 0, element);
//     addLLElement(list, 0, element);
//     EXPECT_EQ(getLinkedListLength(list), 3);
// }

// TEST(deleteLinkedList, when_emptyList_expect_notNullptr) {
//     LinkedList *list = createLinkedList();

//     deleteLinkedList(list);
//     EXPECT_NE(list, nullptr);
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}