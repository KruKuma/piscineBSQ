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

int	ft_parse_header(char *content, t_map *map, int *start);
int	ft_get_cols(char *content, int start);
int	ft_alloc_grid(t_map *map);
int	ft_fill_grid(t_map *map, char *content, int start);

int	ft_parse_map(char *content, t_map *map)
{
	int	start;

	if (!ft_parse_header(content, map, &start))
		return (0);
	map->cols = ft_get_cols(content, start);
	if (map->cols <= 0)
		return (0);
	if (!ft_alloc_grid(map))
		return (0);
	if (!ft_fill_grid(map, content, start))
	{
		ft_free_map(map);
		return (0);
	}
	return (1);
}
