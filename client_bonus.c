/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:12:11 by mfallahi          #+#    #+#             */
/*   Updated: 2022/02/22 00:25:41 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	send(char *s, int pid)
{
	int	i;
	int	j;
	int	b;

	i = -1;
	while (ft_strlen(s) >= ++i)
	{
		j = -1;
		b = 1;
		while (++j < 8)
		{
			if (((int)s[i] & b))
			{
				if (kill(pid, SIGUSR1) == -1)
					return (0);
			}
			else if (((int)s[i] & b) == 0)
				if (kill(pid, SIGUSR2) == -1)
					return (0);
			usleep(100);
			b = b * 2;
		}
	}
	return (1);
}

void	handler_rc(int sig)
{
	write(1, "seen ✔️\n", 8);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*to_send;

	signal(SIGUSR2, &handler_rc);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		to_send = av[2];
		if ((pid <= 0) || !send(to_send, pid))
			write(1, "Wrong PID\n", 10);
	}
	else
		write(1, "Please Enter Valid Arguments\n", 29);
	return (0);
}
