/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:12:07 by mfallahi          #+#    #+#             */
/*   Updated: 2022/02/21 23:30:21 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

int	main(int ac, char **av)
{
	int		pid;
	char	*to_send;

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
