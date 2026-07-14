/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amathey <arn.mathey@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 10:52:25 by amathey           #+#    #+#             */
/*   Updated: 2026/07/14 11:56:54 by amathey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_print_map(t_map *map)
{
	int	col;
	int	row;

	row = 0;
	while (row < map->rows)
	{
		write(1, map->rows, map->cols);
		write(1, "\n", 1);
		row++;
	}
}
