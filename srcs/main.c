/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 09:04:06 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/13 09:44:44 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	char	*file;
	char	*content;
	
	if (argc != 2)
		return (0);
	file = argv[1];
	content = ft_read_file(file);
	if (content == 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
