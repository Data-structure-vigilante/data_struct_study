#include "bintree.h"

// 삽입
AVLTreeNode *insertAVL(AVLTree *tree, AVLTreeNode element);

// 삭제
AVLTreeNode *deleteAVL(AVLTree *tree, int data);

// 검색
AVLTreeNode *searchAVL(AVLTree *tree, int data);

// utils
void leftBalance();
void rightBalance();
Bool rightRotate();
Bool leftRotate();