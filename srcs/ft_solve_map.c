/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 20:00:22 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/13 20:00:22 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**ft_create_dp(t_map *map);
void	ft_free_dp(int **dp, int rows);
void	ft_fill_square(t_map *map, t_square square);

int ft_solve_map(t_map *map)
{
    int **dp;
    t_square largest_square;

    dp = ft_create_dp(map);
    if (dp == 0)
        return (0);
    largest_square.size = 0;
    largest_square.row = 0;
    largest_square.col = 0;
    ft_fill_dp(map, dp, &largest_square);
    ft_fill_square(map, largest_square);
    ft_free_dp(dp, map->rows);
    return (1); 
}
