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

int basic_check(int *tab, int lines, int sticks)
{
    int tmp = 0;
    int cnt = 0;

    for (int i = 0; i < lines; ++i) {
        tmp = tab[i];
        tmp = tmp < 0 ? 0 : tab[i];
        while (tmp > 1)
            tmp -= (sticks + 1);
        if (tmp != 0 && tmp != 1)
            return (1);
        if (tmp == 1)
            cnt++;
    }
    if (cnt % 2 == 0)
        return (1);
    return (0);
}

void random_ia(int *array, int lines)
{
    for (int i = 0; i < lines; ++i) {
        if (array[i] > 0) {
            array[i]--;
            my_putstr("AI removed 1 match(es) from line ");
            my_put_basenbr(i + 1, 10);
            my_putchar('\n');
            break;
        }
    }
}

int test(int *array, int lines, int sticks, int *result)
{
    if (result[1] < sticks && array[result[0]] > result[1])
        result[1] += 1;
    else {
        result[0] += 1;
        while (array[result[0]] <= 0 && result[0] < lines) {
            result[0] += 1;
        }
        result[1] = 1;
    }
    if (result[0] >= lines)
        return (84);
    return (0);
}

int real_ia(int *array, int lines, int sticks)
{
    int result[2];
    result[0] = 0;
    result[1] = 0;

    do {
        array[result[0]] += result[1];
        if (test(array, lines, sticks, result) == 84) {
            random_ia(array, lines);
            return (0);
        }
        array[result[0]] -= result[1];
    } while (win_pos(array, lines, sticks) != 1);
    my_putstr("AI removed ");
    my_put_basenbr(result[1], 10);
    my_putstr(" match(es) from line ");
    my_put_basenbr(result[0] + 1, 10);
    my_putchar('\n');
    return (0);
}

void ia_play(int *array, int lines, int sticks)
{
    real_ia(array, lines, sticks);
}
