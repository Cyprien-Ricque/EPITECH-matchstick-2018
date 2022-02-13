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

void create_tab(int *tab, int lines)
{
    init_tab(tab);
    tab[0] = 1;
    for (int i = 1; i < lines; ++i) {
        tab[i] = tab[i - 1] + 2;
    }
}

void display_tab(int *tab, int lines)
{
    int sticks = 0;

    for (int i = 0; i < (lines * 2); ++i)
        my_putchar('*');
    for (int j = 0; j < lines; ++j) {
        my_putstr("*\n*");
        sticks = 0;
        for (int i = 0; i < (lines * 2 - 1); ++i) {
            if (sticks < tab[j])
                my_putchar(i >= (lines * 2) / 2 - (j * 2) / 2 - 1 ? '|' : ' ');
            else
                my_putchar(' ');
            sticks =
                i >= (lines * 2) / 2 - (j * 2) / 2 - 1 && sticks < tab[j] ?
                    sticks + 1 : sticks;
        }
    }
    my_putstr("*\n");
    for (int i = 0; i < (lines * 2 + 1); ++i)
        my_putchar('*');
}

int check_end(int *array, int lines)
{
    int total = 0;

    for (int i = 0; i < lines; ++i)
        total += array[i] > 0 ? array[i] : 0;
    return (total);
}

int get_sticks(int sticks, int line, int *array)
{
    int removed;
    char *buffer;

    my_putstr("Matches: ");
    buffer = get_next_line(0);
    if (!buffer)
        return (-1);
    removed = number_stick_error(buffer, array, line, sticks);
    return (removed);
}