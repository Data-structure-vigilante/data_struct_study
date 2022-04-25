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

TEST(get, zero_index_empty_list) {
    DoublyList *list = createDoublyList();

    EXPECT_EQ(getDLElement(list, 0), nullptr);
};

TEST(get, zero_index_not_empty_list) {
    DoublyList *list = createDoublyList();
    DoublyListNode element;
    int position = 0;
    element.data = 1;
    element.pRLink = nullptr;
    element.pLLink = nullptr;
    addDLElement(list, 0, element);

    EXPECT_NE(getDLElement(list, 0), nullptr);
};

TEST(get, print_single_element) {
    DoublyList *list = createDoublyList();
    DoublyListNode element;
    int position = 0;
    element.data = 1;
    element.pRLink = nullptr;
    addDLElement(list, 0, element);

    EXPECT_EQ(getDLElement(list, 0)->data, 1);
};

TEST(get, print_elements) {
    DoublyList *list = createDoublyList();
    DoublyListNode element;
    int position = 0;

    element.data = 2;
    element.pRLink = nullptr;
    addDLElement(list, 0, element);
    element.data = 1;
    addDLElement(list, 0, element);
    element.data = 0;
    addDLElement(list, 0, element);

    for (int i = 0; i < 3; ++i)
        EXPECT_EQ(getDLElement(list, i)->data, i);
};

TEST(remove, when_emptyList_expect_minus1) {
    DoublyList *list = createDoublyList();
    EXPECT_EQ(removeDLElement(list, 0), -1);
}

TEST(remove, when_1elementListRemove2position_expect_minus1) {
    DoublyList *list = createDoublyList();

    DoublyListNode element;
    element.data = 2;
    element.pRLink = nullptr;
    element.pLLink = nullptr;
    addDLElement(list, 0, element);
    EXPECT_EQ(removeDLElement(list, 1), -1);
}

TEST(remove, when_1elementListRemove0position_expect_0) {
    DoublyList *list = createDoublyList();

    DoublyListNode element;
    element.data = 2;
    element.pRLink = nullptr;
    element.pLLink = nullptr;
    addDLElement(list, 0, element);
    EXPECT_EQ(removeDLElement(list, 0), 0);
}

// TEST(clear, clear_llist) {
//     DoublyList *list = createDoublyList();
//     DoublyListNode element;

//     element.data = 2;
//     element.pRLink = nullptr;
//     addDLElement(list, 0, element);
//     addDLElement(list, 0, element);
//     addDLElement(list, 0, element);
//     clearDoublyList(list);
//     EXPECT_EQ(list->headerNode.pRLink, &list->headerNode);
//     EXPECT_EQ(list->currentElementCount, 0);
// }

// TEST(getLinkedListLength, when_emptylist_expect_zero) {
//     DoublyList *list = createDoublyList();

//     EXPECT_EQ(getLinkedListLength(list), 0);
// }

// TEST(getLinkedListLength, when_threeElement_expect_zero) {
//     DoublyList *list = createDoublyList();
//     DoublyListNode element;

//     element.data = 2;
//     element.pRLink = nullptr;
//     addDLElement(list, 0, element);
//     addDLElement(list, 0, element);
//     addDLElement(list, 0, element);
//     EXPECT_EQ(getLinkedListLength(list), 3);
// }

// TEST(deleteLinkedList, when_emptyList_expect_notNullptr) {
//     DoublyList *list = createDoublyList();

//     deleteLinkedList(list);
//     EXPECT_NE(list, nullptr);
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}