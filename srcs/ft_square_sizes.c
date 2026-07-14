/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_sizes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 20:25:07 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/13 20:25:07 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_free_square_sizes(int **square_sizes, int rows);

int		**ft_create_square_sizes(t_map *map)
{
    int **square_sizes;
    int row;

    square_sizes = malloc(sizeof(int *) * map->rows);
    if (square_sizes == 0)
        return (0);
    row = 0;
    while (row < map->rows)
    {
        square_sizes[row] = malloc(sizeof(int) * map->cols);
        if (square_sizes[row] == 0)
        {
            ft_free_square_sizes(square_sizes, row);
            return (0);
        }
        row++;
    }
    return (square_sizes);
}

void	ft_free_square_sizes(int **square_sizes, int rows)
{
    int row;

    if (square_sizes == 0)
        return ;
    row = 0;
    while (row < rows)
    {
        if (square_sizes[row] != 0)
            free(square_sizes[row]);
        row++;
    }
    free(square_sizes);
}
