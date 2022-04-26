
#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_

typedef struct ListNodeType {
    int data;
    struct ListNodeType *pLink;
} ListNode;

typedef struct CircularListType {
    int currentElementCount;
    ListNode headerNode;
} CircularList;

CircularList *createCircularList();
int addCLElement(CircularList *pList, int position, ListNode element);
int removeCLElement(CircularList *pList, int position);
ListNode *getCLElement(CircularList *pList, int position);
void clearCircularList(CircularList *pList);
int getCircularListLength(CircularList *pList);
void deleteCircularList(CircularList *pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif
