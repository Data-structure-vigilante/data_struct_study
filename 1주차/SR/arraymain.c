#include "arraylist.h"

int	main() {
	ArrayList	*list;
	list = createArrayList(10);

	/*
		addALElement
	*/
	for (int i=0;i<list->maxElementCount;i++) {
		ArrayListNode	temp;
		temp.data = i;
		addALElement(list, i, temp);
	}
	displayArrayList(list);

	if(isArrayListFull(list))
		printf("list is full\n");
	else
		printf("list is not full\n");

	deleteArrayList(list);
}