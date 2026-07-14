/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_stdin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 23:08:41 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/14 23:08:41 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_process_stdin(void)
{
	char	*content;
	t_map	map;

	ft_init_map(&map);
	content = ft_read_fd(0);
	if (content == 0)
		return (ft_process_error(content, &map));
	if (!ft_parse_map(content, &map))
		return (ft_process_error(content, &map));
	if (!ft_solve_map(&map))
		return (ft_process_error(content, &map));
	ft_print_map(&map);
	ft_free_map(&map);
	free(content);
	return (1);
}
