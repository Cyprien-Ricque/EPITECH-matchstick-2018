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

int get_line(int lines, int *array)
{
    int line;
    char *buffer;

    do {
        my_putstr("Line: ");
        buffer = get_next_line(0);
        if (!buffer)
            return (-1);
        line = line_error(buffer, lines, array);
    } while (line == 0);
    return (line);
}

int info_pl(int *array, int lines, int sticks)
{
    int line = get_line(lines, array);
    int to_rm = 0;

    if (line == -1)
        return (84);
    to_rm = get_sticks(sticks, line, array);
    if (to_rm == -1)
        return (84);
    else if (to_rm == 0)
        info_pl(array, lines, sticks);
    else {
        array[line - 1] -= to_rm;
        my_putstr("Player removed ");
        my_put_basenbr(to_rm, 10);
        my_putstr(" match(es) from line ");
        my_put_basenbr(line, 10),
        my_putchar('\n');
    }
}

int take_info(int player, int *array, int lines, int sticks)
{
    if (player == 2) {
        my_putstr("\n\nAI's turn...\n");
        ia_play(array, lines, sticks);
        return (0);
    }
    my_putstr("\n\nYour turn:\n");
    if (info_pl(array, lines, sticks) == 84)
        return (84);
    return (0);
}

int update(int lines, int sticks)
{
    int array[100];
    int player = 1;

    create_tab(array, lines);
    while (check_end(array, lines) > 0) {
        display_tab(array, lines);
        if (take_info(player, array, lines, sticks) == 84)
            return (0);
        player = player == 1 ? 2 : 1;
    }
    display_tab(array, lines);
    if (player == 1) {
        my_putstr("\nI lost... snif... but I'll get you next time!!");
        return (1);
    } else {
        my_putstr("\nYou lost, too bad...");
        return (2);
    }
}

int main(int ac, char **av)
{
    int value = 0;
    int lines = ac == 3 ? my_getnbr(av[1]) : usage();
    int sticks = ac == 3 ? my_getnbr(av[2]) : 0;

    if (ac != 3)
        return (84);
    value = update(lines, sticks);
    my_putchar('\n');
    return (value);
}