/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 11:30:56 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/13 14:07:12 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_parse_first_line(char *str)
{
	int	i;

	while (str[i] != '\0')
	{
		if (str[i] != '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_parse_header(char *str, t_map *map, int *start)
{
	int	n_len;
	int	i;

	n_len = ft_parse_first_line(str);
	if (n_len < 4)
		return (0);
	map->empty = str[n_len - 3];
	map->obstacle = str[n_len - 2];
	map->full = str[n_len - 1];
	if (!ft_is_printable(map->empty) || !ft_is_printable(map->obstacle)
		|| !ft_is_printable(map->full))
		return (0);
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	i = 0;
	while (i < n_len - 3)
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	map->rows = ft_atoi(str, n_len - 3);
	*start = n_len + 1;
	return (map->rows > 0);
}

int	ft_parse_map(char *content, t_map *map)
{
	int	start;

	if (!ft_parse_header(content, map, &start))
		return (0);
	return (0);
}
