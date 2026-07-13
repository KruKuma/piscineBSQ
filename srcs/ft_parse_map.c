/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 11:30:56 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/13 13:40:01 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_parse_header(char *contents, t_map *map, int start)
{
	
}

int	ft_parse_map(char *content, t_map *map)
{
	int	start;

	if (!ft_parse_header(content, map, &start))
		return (0);
	return (0);
}
