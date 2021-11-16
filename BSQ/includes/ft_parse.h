#ifndef FT_PARSE_H
# define FT_PARSE_H
# include "ft_lib.h"
# include "ft_core.h"

t_map	*parse_map(char *file_content);
int		validate_sequence(char *line);
int		validate_first_line(char *line);
int		validate_len(char **lines);
int		count_lines(char **lines);
int		validate_grid(char **lines, char empty, char block);
int		**make_grid(char **lines, t_map map);
char	*fill_chars(t_map *map, char *str);
void	tr_map_grid(int *buffer, char c, char empty, char block);
void	destroy_grid(t_map map);

#endif
