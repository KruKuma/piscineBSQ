#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstactle;
	char	full;
	char	**grid;
} t_map;


typedef struct s_square
{
	int	size;
	int	row;
	int	col;
} t_square;

char	*ft_read_file(char *filename);

#endif
