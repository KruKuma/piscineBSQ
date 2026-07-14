/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 23:20:53 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/14 23:20:53 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_process_error(char *content, t_map *map)
{
	if (content != 0)
		free(content);
	ft_free_map(map);
	write(1, "map error\n", 10);
	return (1);
}
