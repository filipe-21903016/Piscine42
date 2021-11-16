#ifndef FT_FILE_H
# define FT_FILE_H
# define BUFFER_SIZE 4096 
# include <sys/stat.h>
# include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node{
	int		key;
	char	*value;
} t_node;

char	*readlines(int fd);

#endif
