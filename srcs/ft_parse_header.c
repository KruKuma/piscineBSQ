/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 19:25:31 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/13 19:25:31 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_first_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check_symbols(t_map *map)
{
	if (!ft_is_printable(map->empty) || !ft_is_printable(map->obstacle)
		|| !ft_is_printable(map->full))
		return (0);
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full)
		return (0);
	return (1);
}

int	ft_check_header_number(char *str, int end)
{
	int	i;

	if (end <= 0)
		return (0);
	i = 0;
	while (i < end)
	{
		if (!ft_is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse_header(char *content, t_map *map, int *start)
{
	int	nl;

	nl = ft_first_newline(content);
	if (nl < 4)
		return (0);
	map->empty = content[nl - 3];
	map->obstacle = content[nl - 2];
	map->full = content[nl - 1];
	if (!ft_check_symbols(map))
		return (0);
	if (!ft_check_header_number(content, nl - 3))
		return (0);
	map->rows = ft_atoi_n(content, nl - 3);
	if (map->rows <= 0)
		return (0);
	*start = nl + 1;
	return (1);
}
