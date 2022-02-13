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

int usage(void)
{
    my_putstr("USAGE:\n");
    my_putstr("./matchstick LINES STICKS\n");
    my_putstr("    LINES    lines to display\n");
    my_putstr("    STICKS   maximum sticks which can be removed\n");
    return (84);
}

int number_stick_error(char *to_rm, int *array, int line, int sticks)
{
    for (int i = 0; to_rm[i]; ++i) {
        if (to_rm[i] < '0' || to_rm[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (0);
        }
    }
    if (my_getnbr(to_rm) > sticks) {
        my_putstr("Error: you cannot remove more than ");
        my_put_basenbr(sticks, 10);
        my_putstr(" matches per turn\n");
        return (0);
    }
    if (my_getnbr(to_rm) > array[line - 1]) {
        my_putstr("Error: not enough matches on this line\n");
        return (0);
    }
    if (my_getnbr(to_rm) == 0)
        my_putstr("Error: you have to remove at least one match\n");
    return (my_getnbr(to_rm));
}

int line_error(char *buffer, int lines, int *array)
{
    int line = my_getnbr(buffer);

    for (int i = 0; buffer[i]; ++i) {
        if (buffer[i] < '0' || buffer[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)\n");
            return (0);
        }
    }
    if (line <= 0 || line > lines) {
        my_putstr("Error: this line is out of range\n");
        return (0);
    }
    return (line);
}