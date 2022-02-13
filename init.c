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

void init_tab(int *tab)
{
    for (int j = 0; j < 100; ++j)
        tab[j] = 0;
}

int higher(int line, int sticks)
{
    int tmp = 1;

    while (line - tmp >= 0)
        tmp += tmp;
    return (tmp / 2);
}

int pos(int nb)
{
    int i = 0;

    while (nb > 1) {
        nb = nb / 2;
        ++i;
    }
    return (i);
}

void split(int line, int *tab, int sticks)
{
    int tmp;

    while (line > sticks)
        line -= (sticks + 1);
    while (line > 0) {
        tmp = higher(line, sticks);
        tab[pos(tmp)] += 1;
        line -= tmp;
    }
}

int pos_rev(int i)
{
    int nb = 1;

    while (i > 0) {
        nb = nb * 2;
        i--;
    }
    return (nb);
}