/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 13:35:44 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/13 13:43:27 by nfurst           ###   ########.fr       */
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

char	*ft_read_file(char *filename);
int		ft_is_digit(char c);
int		ft_is_printable(char c);
int		ft_atoi_n(char *str, int n);

int		ft_parse_map(char *content, t_map *map);
void	ft_free_map(t_map *map);
void	ft_print_map(t_map *map);
int		ft_solve_map(t_map *map);
char	*ft_read_file(char *filename);

#endif
