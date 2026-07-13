/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathey <arn.mathey@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:52:25 by amathey           #+#    #+#             */
/*   Updated: 2026/07/13 13:27:30 by amathey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include "bsq.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int len)
{
	int	i;

	i = 0;
	while(i * i >= len)
		i++;
	if (i * i == len)
		return (i);
	return (0);
	}

int ft_print_map(char *map[9][9], int len)
{
	int	side;
	int	col;
	int row;
	int	i;
	
	col = 0;
	row = 0;
	i = 0;
	side = ft_sqrt(len);
	if (side == 0)
		return (1);
	
	map = malloc(sizeof(char) * side + 1);
	while(i++ < side + 1)
		map[i] = malloc(sizeof(char) * side + 1);
	if (side == 0)
		return (0);
	while(row < side)
	{
		while(col < side)
		{
			map[row][col] = "0";
			write(1, map[row][col], 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
	return (1);
}

int	main(void)
{
	char *map = "00000000000000000000";
	
	printf("the square = %i \n", ft_sqrt(25));
	ft_print_map(&map, 16);
	while (map[i++])
		free(map[i]);
	return(0);
}