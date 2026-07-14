/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 09:04:06 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/14 11:31:46 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	char	*file;
	char	*content;
	t_map	map;

	if (argc != 2)
		return (0);
	file = argv[1];
	content = ft_read_file(file);
	if (content == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	ft_init_map(&map);
	if (!ft_parse_map(content, &map))
	{
		free(content);
		write(2, "map error\n", 10);
		return (1);
	}
	if (!ft_solve_map(&map))
	{
		ft_free_map(&map);
		free(content);
		write(2, "map error\n", 10);
		return (1);
	}
	ft_print_map(&map);
	ft_free_map(&map);
	free(content);
	return (0);
}
