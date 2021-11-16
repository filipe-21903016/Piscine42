#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include "ft_functions.h"

void	initialize_skyscraper(int *skyscraper, int width, int height);
int		*get_skyscraper(int width, int height);
void	print_skyscraper(int *skyscraper, int width, int height);
int		find_next_empty(int *skyscraper, int *col, int *row);
int		get_value(int *skyscraper, int col, int row);
void	set_value(int *skyscraper, int col, int row, int value);
int		is_correct_order(int *skyscraper, int *input);
int		check_down(int *skyscraper, int *input);
int		check_up(int *skyscraper, int *input);
int		check_left(int *skyscraper, int *input);
int		check_right(int *skyscraper, int *input);
int		is_valid_guess(int *skyscraper, int col, int row, int value);
int		is_char_valid(char c, int i);

#endif
