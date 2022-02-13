/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

void ia_play(int *array, int lines, int sticks);
void display_tab(int *tab, int lines);
void init_tab(int *tab);
int usage(void);
int number_stick_error(char *to_rm, int *array, int line, int sticks);
int line_error(char *buffer, int lines, int *array);
void create_tab(int *tab, int lines);
void display_tab(int *tab, int lines);
int check_end(int *array, int lines);
int get_sticks(int sticks, int line, int *array);
void init_tab(int *tab);
int higher(int line, int sticks);
int pos(int nb);
void split(int line, int *tab, int sticks);
int pos_rev(int i);
int win_pos(int *array, int lines, int sticks);
int basic_check(int *tab, int lines, int sticks);

#endif /* MATCHSTICK_H_ */
