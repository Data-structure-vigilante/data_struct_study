typedef struct PoliNodeType {
    float coef;
    int degree;
    struct PoliNodeType *pLink;
} PoliNode;

typedef struct PoliType {
    int currentElementCount;
    PoliNode headerNode;
} Polinomial;

//다항식 생성
Polinomial *createPolinomial();

//다항식 연산
int addPoliNode(Polinomial *polinomial, float coef, int degree);

/* 이자로 받은 다항식 두개를 더해서 새로운 다항식을 리턴 */
Polinomial *sumPoliNomial(Polinomial *first, Polinomial *second);
Polinomial *subPoliNomial(Polinomial *dest, Polinomial *src);