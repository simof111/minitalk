/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:12:28 by mfallahi          #+#    #+#             */
/*   Updated: 2022/02/21 23:21:57 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_p = 0;

void	reset(char *c, int *bit, int *count, int si_pid)
{
	*c = 0;
	*bit = 1;
	*count = -1;
	g_p = si_pid;
}

void	handler(int c, siginfo_t *info, void *context)
{
	static char	print;
	static int	bit;
	static int	count;

	if (g_p != info->si_pid)
		reset(&print, &bit, &count, info->si_pid);
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
		if (print == 0)
			kill(g_p, SIGUSR2);
		else
			write(1, &print, 1);
		reset(&print, &bit, &count, info->si_pid);
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
