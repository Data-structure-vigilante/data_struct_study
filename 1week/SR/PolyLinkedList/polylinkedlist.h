
#ifndef _PolyLIST_
#define _PolyLIST_

typedef struct ListNodeType
{
    float coef;
    int degree;
    struct ListNodeType *pLink;
} PolyListNode;

typedef struct PolyListType
{
    int currentElementCount; // ���� ����� ������ ����
    PolyListNode headerNode; // ��� ���(Header Node)
} PolyList;

PolyList *createPolyList();
int addPLElement(PolyList *pList, int position, PolyListNode element);
int removePLElement(PolyList *pList, int position);
PolyListNode *getPLElement(PolyList *pList, int position);

void clearPolyList(PolyList *pList);
int getPolyListLength(PolyList *pList);
void deletePolyList(PolyList *pList);
PolyList *sumPolyList(PolyList *listA, PolyList *listB);
int addPolyNodeLast(PolyList *pList, float coef, int degree);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif
