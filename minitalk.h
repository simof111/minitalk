/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:12:26 by mfallahi          #+#    #+#             */
/*   Updated: 2022/02/21 23:30:30 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H 

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int			send(char *s, int pid);
int			ft_strlen(char *str);
long long	ft_atoi(const char *nptr);
void		ft_putchar_fd(char c);
void		ft_putnbr(int n);
void		handler(int c);
#endif