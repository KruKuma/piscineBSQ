/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 23:14:52 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/14 23:14:52 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_append_data(char *old, int old_size, char *buffer, int buffer_size);

char	*ft_read_fd(int fd)
{
	char	buffer[1024];
	char	*content;
	int		bytes;
	int		total;

	content = malloc(sizeof(char));
	if (content == 0)
		return (0);
	content[0] = '\0';
	total = 0;
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		content = ft_append_data(content, total, buffer, bytes);
		if (content == 0)
			return (0);
		total += bytes;
		bytes = read(fd, buffer, 1024);
	}
	if (bytes < 0)
	{
		free(content);
		return (0);
	}
	return (content);
}
