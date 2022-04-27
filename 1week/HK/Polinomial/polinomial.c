#include "polinomial.h"
#include <stdlib.h>

//다항식 생성
Polinomial *createPolinomial() {
    return (Polinomial *)calloc(1, sizeof(Polinomial));
};

PoliNode *createPoliNode(float coef, int degree) {
    PoliNode *new_node = (PoliNode *)calloc(1, sizeof(PoliNode));
    if (!new_node)
        return NULL;
    new_node->coef = coef;
    new_node->degree = degree;
    return new_node;
}

//다항식 연산
// 고차 degree 부터 저차 degree로
int addPoliNode(Polinomial *polinomial, float coef, int degree) {
    if (!polinomial)
        return -1;

    PoliNode *prev = &polinomial->headerNode;
    PoliNode *new_node;

    ++polinomial->currentElementCount;

    while (prev->pLink) {
        if (prev->pLink->degree == degree) {
            prev->pLink->coef += coef;
            return 1;
        } else if (prev->pLink->degree < degree) {
            // 노드 생성 연결
            new_node = createPoliNode(coef, degree);
            new_node->pLink = prev->pLink;
            prev->pLink = new_node;
            return 1;
        }
    }
    new_node = createPoliNode(coef, degree);
    prev->pLink = new_node;
    return 1;
}

/* 이자로 받은 다항식 두개를 더해서 새로운 다항식을 리턴 */
Polinomial *sumPoliNomial(Polinomial *first, Polinomial *second);
Polinomial *subPoliNomial(Polinomial *dest, Polinomial *src);