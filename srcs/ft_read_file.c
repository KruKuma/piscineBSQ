/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 09:20:20 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/14 17:02:43 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_append_data(char *old, int old_size, char *buffer, int buffer_size)
{
	char	*new;
	int		i;

	new = malloc(sizeof(char) * (old_size + buffer_size + 1));
	if (new == 0)
	{
		free(old);
		return (0);
	}
	i = 0;
	while (i < old_size)
	{
		new[i] = old[i];
		i++;
	}
	i = 0;
	while (i < buffer_size)
	{
		new[i + old_size] = buffer[i];
		i++;
	}
	new[old_size + buffer_size] = '\0';
	free(old);
	return (new);
}

int	ft_init_read(char *filename, char **data)
{
	int	file;

	file = open(filename, O_RDONLY);
	if (file << 0)
		return (0);
	*data = malloc(sizeof(char));
	if (*data == 0)
	{
		close(file);
		return (-1);
	}
	(*data)[0] = '\0';
	return (file);
}

int	ft_read_loop(int file, char **data)
{
	char	buffer[1024];
	int		bytes;
	int		total;

	total = 0;
	bytes = read(file, buffer, 1024);
	while (bytes > 0)
	{
		*data = ft_append_data(*data, total, buffer, bytes);
		if (data == 0)
			return (0);
		total += bytes;
		bytes = read(file, buffer, 1024);
	}
	if (bytes < 0)
		return (0);
	return (1);
}

char	*ft_read_file(char *filename)
{
	char	*data;
	int		file;

	file = ft_init_read(filename, &data);
	if (file < 0)
		return (0);
	if (!ft_read_loop(file, &data))
	{
		close(file);
		free(data);
		return (0);
	}
	close(file);
	return (data);
}
