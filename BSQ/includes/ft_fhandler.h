#ifndef FT_FHANDLER_H
# define FT_FHANDLER_H
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_core.h"
# include <stdio.h>
# include "ft_lib.h"
# include "ft_realloc.h"

char		*read_file(int fd);
int			is_file_valid(char *file_content);
void		ft_puterr(char *str, int size);

#endif
