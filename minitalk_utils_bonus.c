/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:12:17 by mfallahi          #+#    #+#             */
/*   Updated: 2022/02/21 23:19:17 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

long long	ft_atoi(const char *nptr)
{
	int			i;
	int			signe;
	long long	rslt;

	i = 0;
	signe = 1;
	rslt = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		rslt = rslt * 10 + nptr[i] - 48;
		i++;
	}
	return (rslt * signe);
}

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		ft_putchar_fd('-');
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar_fd(nb % 10 + '0');
	}
	else
		ft_putchar_fd('0' + nb);
}
