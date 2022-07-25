/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:12:33 by mfallahi          #+#    #+#             */
/*   Updated: 2022/02/21 23:28:00 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int c)
{
	static char	print = 0;
	static int	bit = 1;
	static int	count = -1;

	count++;
	if (count < 8)
	{
		if (c == SIGUSR1)
		{
			print = (print | bit);
			bit *= 2;
		}
		else if (c == SIGUSR2)
			bit *= 2;
	}
	if (count == 7)
	{
		write(1, &print, 1);
		print = 0;
		count = -1;
		bit = 1;
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, &handler);
	signal(SIGUSR2, &handler);
	while (1)
		pause();
	return (0);
}
