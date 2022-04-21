/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:22:18 by hekang            #+#    #+#             */
/*   Updated: 2022/04/21 10:11:18 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>

ArrayList *createArrayList(int maxElementCount) {
    if (maxElementCount <= 0) {
        return NULL;
    }
    ArrayList *array;

    array = (ArrayList *)malloc(sizeof(ArrayList));
    array->pElement =
        (ArrayListNode *)malloc(maxElementCount * sizeof(ArrayListNode));
    array->maxElementCount = maxElementCount;
    array->currentElementCount = 0;
    return array;
}

void deleteArrayList(ArrayList *pList) {
    if (!pList)
        return;
    free(pList->pElement);
    free(pList);
}

int isArrayListFull(ArrayList *pList) {
    if (!pList)
        return FALSE;
    return pList->currentElementCount == pList->maxElementCount;
}

// Return : 성공 시 - index  값 리턴, 실패 시 -1 리턴
// input : position > currentElementCount 면, 마지막에 추가
int addALElement(ArrayList *pList, int position, ArrayListNode element) {
    if (!pList || isArrayListFull(pList))
        return -1;
    int last_position = pList->currentElementCount - 1;
    ArrayListNode *array = pList->pElement;
    if (position > last_position) {
        array[last_position + 1] = element;
        ++pList->currentElementCount;
        return last_position + 1;
    }

    for (int current = last_position; current >= position; --current)
        array[current + 1] = array[current];
    array[position] = element;
    ++pList->currentElementCount;
    return position;
}

int removeALElement(ArrayList *pList, int position) {
    if (!pList)
        return -1;
    int last_position = pList->currentElementCount - 1;
    ArrayListNode *array = pList->pElement;

    if (position > last_position || position < 0)
        return -1;
    for (int current = position; current < last_position; ++current)
        array[current] = array[current + 1];
    --pList->currentElementCount;
    return position;
}

ArrayListNode *getALElement(ArrayList *pList, int position) {
    if (!pList)
        return NULL;
    int last_position = pList->currentElementCount - 1;
    ArrayListNode *array = pList->pElement;

    if (position > last_position || position < 0)
        return NULL;
    return &array[position];
}

void displayArrayList(ArrayList *pList) {
    if (!pList)
        return;
    ArrayListNode *array = pList->pElement;
    int last_position = pList->currentElementCount - 1;

    for (int cur = 0; cur <= last_position; ++cur)
        printf("%dth element: %d\n", cur, array[cur].data);
}

void clearArrayList(ArrayList *pList) {
    if (!pList)
        return;
    pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList *pList) {
    if (!pList)
        return -1;
    return pList->currentElementCount;
}
