/*
** EPITECH PROJECT, 2018
** my_popup
** File description:
** my_popup
*/

#include "include/matchstick.h"
#include "include/my.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int win_pos(int *array, int lines, int sticks)
{
    int tab[100];
    int count = 0;
    int e = 1;
    int indice = 0;

    init_tab(tab);
    for (int i = 0; i < lines; ++i)
        split(array[i], tab, sticks);
    if (basic_check(array, lines, sticks) == 0)
        return (1);
    for (int i = 0; i < 30; ++i) {
        if (tab[i] % 2 != 0 && pos_rev(i) <= sticks)
            return (0);
        if (tab[i] > 0 && i > 0 && pos_rev(i) <= sticks)
            indice = 1;
    }
    if (indice == 1)
        return (1);
    return (0);
}