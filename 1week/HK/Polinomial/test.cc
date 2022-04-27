#include "../../../gtest/include/gtest/gtest.h"
#include "polinomial.h"
#include <stdio.h>

// testCaseName When_StateUnderTest_Expect_ExpectedBehavior
TEST(createPolinomial, when_create_expect_success) {
    Polinomial *poli = createPolinomial();

    EXPECT_NE(poli, nullptr);
    EXPECT_EQ(poli->currentElementCount, 0);
}

TEST(addPoliNode, when_addToEmptyPolinomial_expect_success) {
    Polinomial *poli = createPolinomial();

    addPoliNode(poli, 1.2, 3);
    EXPECT_EQ(poli->currentElementCount, 1);
    EXPECT_EQ(poli->headerNode.pLink->coef, (float)1.2);
    EXPECT_EQ(poli->headerNode.pLink->degree, 3);
}

TEST(addPoliNode, when_addExistDegreePolinomial_expect_success) {
    Polinomial *poli = createPolinomial();

    addPoliNode(poli, 1.2, 3);
    addPoliNode(poli, 2.0, 3);
    EXPECT_EQ(poli->currentElementCount, 1);
    EXPECT_EQ(poli->headerNode.pLink->coef, (float)3.2);
    EXPECT_EQ(poli->headerNode.pLink->degree, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}