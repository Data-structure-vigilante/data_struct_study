#include "avltree.h"

int main() {
    AVLTree *tree = makeAVLTree();
    AVLTreeNode element;

    for (int i = 1; i <= 9; ++i) {
        element.data = i;
        insertAVL(tree, element);
    }
}