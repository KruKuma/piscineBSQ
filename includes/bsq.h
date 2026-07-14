/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:35:44 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/14 14:02:05 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_square
{
	int	size;
	int	row;
	int	col;
}	t_square;

/* Reading */
char	*ft_read_file(char *filename);
char	*ft_read_fd(int fd);

/* Processing */
int		ft_process_file(char *filename);
int		ft_process_stdin(void);
int		ft_process_error(char *content, t_map *map);

/* Parsing */
int		ft_parse_map(char *content, t_map *map);

/* Solving */
int		ft_solve_map(t_map *map);

/* Map helpers */
void	ft_init_map(t_map *map);
void	ft_free_map(t_map *map);
void	ft_print_map(t_map *map);

/* Utils */
int		ft_is_digit(char c);
int		ft_is_printable(char c);
int		ft_atoi_n(char *str, int n);

#endif
