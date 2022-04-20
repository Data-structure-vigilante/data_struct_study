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

#include "arraylist.h"
#include <stdio.h>

int main() {
    ArrayList *array;
    array = createArrayList(10);

    ArrayListNode node;
    node.data = 1;
    addALElement(array, 1, node);
    node.data = 2;
    addALElement(array, 1, node);
    node.data = 3;
    addALElement(array, 1, node);
    displayArrayList(array);

    removeALElement(array, 0);
    displayArrayList(array);
    removeALElement(array, 10);
    displayArrayList(array);

    deleteArrayList(array);

    return 0;
}