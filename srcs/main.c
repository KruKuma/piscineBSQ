/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 09:04:06 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/13 13:34:13 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	char	*file;
	char	*content;
	char	*map;

	if (argc != 2)
		return (0);
	file = argv[1];
	content = ft_read_file(file);
	if (content == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (!parse_map(content, &map))
	{
		write(2, "map error\n", 10);
		return (1);
	}
	return (0);
}
