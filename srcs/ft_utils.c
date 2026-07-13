/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfurst <nfurst@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 09:59:39 by nfurst            #+#    #+#             */
/*   Updated: 2026/07/13 11:02:31 by nfurst           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	ft_atoi(char *str, int n)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (i < n)
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}
