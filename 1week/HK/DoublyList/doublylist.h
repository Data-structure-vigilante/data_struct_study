#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

typedef struct DoublyListNodeType {
    int data;
    struct DoublyListNodeType *pLLink;
    struct DoublyListNodeType *pRLink;
} DoublyListNode;

typedef struct DoublyListType {
    int currentElementCount;
    DoublyListNode headerNode;
} DoublyList;

DoublyList *createDoublyList();
void deleteDoublyList(DoublyList *pList);
int addDLElement(DoublyList *pList, int position, DoublyListNode element);
int removeDLElement(DoublyList *pList, int position);
void clearDoublyList(DoublyList *pList);
int getDoublyListLength(DoublyList *pList);
DoublyListNode *getDLElement(DoublyList *pList, int position);
void displayDoublyList(DoublyList *pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif
