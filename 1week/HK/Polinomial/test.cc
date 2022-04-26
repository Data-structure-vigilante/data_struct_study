#include "../../../gtest/include/gtest/gtest.h"
#include "polinomial.h"
#include <stdio.h>

// testCaseName When_StateUnderTest_Expect_ExpectedBehavior

TEST(create, must_success) { EXPECT_NE(createCircularList(), nullptr); };
TEST(create, initial_check) {
    EXPECT_EQ(createCircularList()->currentElementCount, 0);
    EXPECT_EQ(createCircularList()->headerNode.pLink, nullptr);
    EXPECT_EQ(createCircularList()->headerNode.data, 0);
};

TEST(addCLElement, zero_index_empty_list) {
    CircularList *list = createCircularList();
    ListNode element;
    int position = 0;

    element.data = 1;
    element.pLink = nullptr;

    EXPECT_EQ(addCLElement(list, position, element), position);
    EXPECT_EQ(list->headerNode.pLink, list->headerNode.pLink->pLink);
}

TEST(addCLElement, when_addOneNodeFirstPosition_expect_canCirculate) {
    CircularList *list = createCircularList();
    ListNode element;
    int position = 0;

    element.data = 1;
    element.pLink = nullptr;
    addCLElement(list, position, element);
    EXPECT_EQ(list->headerNode.pLink, list->headerNode.pLink->pLink);
    EXPECT_EQ(list->headerNode.pLink->pLink, list->headerNode.pLink->pLink->pLink->pLink);

}

TEST(addCLElement, when_addTwoNodeFirstPosition_expect_canCirculate) {
    CircularList *list = createCircularList();
    ListNode element;
    int position = 0;

    element.data = 1;
    element.pLink = nullptr;
    addCLElement(list, position, element);
    addCLElement(list, position, element);
    EXPECT_EQ(list->headerNode.pLink, list->headerNode.pLink->pLink->pLink);
    EXPECT_EQ(list->headerNode.pLink->pLink, list->headerNode.pLink->pLink->pLink->pLink);
}

TEST(addCLElement, when_addNodeToLastPosition_expect_canCirculate) {
    CircularList *list = createCircularList();
    ListNode element;

    element.data = 1;
    element.pLink = nullptr;
    addCLElement(list, 0, element);
    addCLElement(list, 1, element);

    EXPECT_EQ(list->headerNode.pLink, list->headerNode.pLink->pLink->pLink);
    EXPECT_EQ(list->headerNode.pLink->pLink, list->headerNode.pLink->pLink->pLink->pLink);
}

TEST(addCLElement, when_addNodeToMiddlePosition_expect_canCirculate) {
    CircularList *list = createCircularList();
    ListNode element;

    element.data = 1;
    element.pLink = nullptr;
    addCLElement(list, 0, element);
    addCLElement(list, 0, element);
    addCLElement(list, 1, element);

    EXPECT_EQ(list->headerNode.pLink, list->headerNode.pLink->pLink->pLink->pLink);
    EXPECT_EQ(list->headerNode.pLink->pLink, list->headerNode.pLink->pLink->pLink->pLink->pLink);
}


TEST(removeCLElement, when_emptyList_expect_minus1) {
    CircularList *list = createCircularList();

    EXPECT_EQ(removeCLElement(list, 0), -1);
}

TEST(removeCLElement, when_nullptr_expect_minus1) {
    EXPECT_EQ(removeCLElement(nullptr, 0), -1);
}

TEST(removeCLElement, when_oneElement_expect_position) {
    CircularList *list = createCircularList();
    ListNode element;

    element.data = 1;
    element.pLink = nullptr;

    addCLElement(list, 0, element);
    EXPECT_EQ(removeCLElement(list, 0), 0);
    EXPECT_EQ(list->currentElementCount, 0);
    EXPECT_EQ(list->headerNode.pLink, nullptr);
}

// TEST(removeCLElement, when_ManyElementRemoveMiddlePosition_expect_position) {
//     CircularList *list = createCircularList();
//     ListNode element;

//     element.pLink = nullptr;
//     element.data = 0;
//     addCLElement(list, 0, element);
//     element.data = 1;
//     addCLElement(list, 0, element);
//     element.data = 2;
//     addCLElement(list, 0, element);

//     EXPECT_EQ(removeCLElement(list, 1), 1);
//     EXPECT_EQ(list->currentElementCount, 2);
//     EXPECT_EQ(list->headerNode.pLink->pLink->data, 0);
//     EXPECT_EQ(list->headerNode.pLink->data, 2);
// }
// TEST(add, zero_index_not_empty_list) {
//     CircularList *list = createCircularList();
//     ListNode element;
//     int position = 0;
//     element.data = 1;
//     element.pLink = nullptr;

//     addCLElement(list, 0, element);
//     EXPECT_EQ(addCLElement(list, position, element), position);
// }

// TEST(add, overflow_index_empty_list) {
//     CircularList *list = createCircularList();
//     ListNode element;
//     int position = 1;

//     element.data = 1;
//     element.pLink = nullptr;

//     EXPECT_EQ(addCLElement(list, position, element), -1);
// };

// TEST(get, zero_index_empty_list) {
//     CircularList *list = createCircularList();

//     EXPECT_EQ(getCLElement(list, 0), nullptr);
// };

// TEST(get, zero_index_not_empty_list) {
//     CircularList *list = createCircularList();
//     ListNode element;
//     int position = 0;
//     element.data = 1;
//     element.pLink = nullptr;
//     addCLElement(list, 0, element);

//     EXPECT_NE(getCLElement(list, 0), nullptr);
// };

// TEST(get, print_single_element) {
//     CircularList *list = createCircularList();
//     ListNode element;
//     int position = 0;
//     element.data = 1;
//     element.pLink = nullptr;
//     addCLElement(list, 0, element);

//     EXPECT_EQ(getCLElement(list, 0)->data, 1);
// };

// TEST(get, print_elements) {
//     CircularList *list = createCircularList();
//     ListNode element;
//     int position = 0;

//     element.data = 2;
//     element.pLink = nullptr;
//     addCLElement(list, 0, element);
//     element.data = 1;
//     addCLElement(list, 0, element);
//     element.data = 0;
//     addCLElement(list, 0, element);

//     for (int i = 0; i < 3; ++i)
//         EXPECT_EQ(getCLElement(list, i)->data, i);
// };

// TEST(clear, clear_llist) {
//     CircularList *list = createCircularList();
//     ListNode element;

//     element.data = 2;
//     element.pLink = nullptr;
//     addCLElement(list, 0, element);
//     addCLElement(list, 0, element);
//     addCLElement(list, 0, element);
//     clearCircularList(list);
//     EXPECT_EQ(list->headerNode.pLink, nullptr);
//     EXPECT_EQ(list->currentElementCount, 0);
// }

// TEST(getCircularListLength, when_emptylist_expect_zero) {
//     CircularList *list = createCircularList();

//     EXPECT_EQ(getCircularListLength(list), 0);
// }

// TEST(getCircularListLength, when_threeElement_expect_zero) {
//     CircularList *list = createCircularList();
//     ListNode element;

//     element.data = 2;
//     element.pLink = nullptr;
//     addCLElement(list, 0, element);
//     addCLElement(list, 0, element);
//     addCLElement(list, 0, element);
//     EXPECT_EQ(getCircularListLength(list), 3);
// }

// TEST(deleteCircularList, when_emptyList_expect_notNullptr) {
//     CircularList *list = createCircularList();

//     deleteCircularList(list);
//     EXPECT_NE(list, nullptr);
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}