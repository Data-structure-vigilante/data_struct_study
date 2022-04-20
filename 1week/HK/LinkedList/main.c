/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:22:29 by hekang            #+#    #+#             */
/*   Updated: 2022/04/18 11:59:58 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>

int main() {
    LinkedList *list = createLinkedList();
    ListNode element;
    int position = 0;

    element.data = 2;
    element.pLink = NULL;
    addLLElement(list, 0, element);
    element.data = 1;
    addLLElement(list, 0, element);
    element.data = 0;
    addLLElement(list, 0, element);
    for (int i = 0; i < 3; ++i)
        printf("%d\n", getLLElement(list, i)->data);
    return 0;
}