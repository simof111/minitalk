/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfallahi <mfallahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:12:38 by mfallahi          #+#    #+#             */
/*   Updated: 2022/02/21 23:30:52 by mfallahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H 

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void		handler_rc(int sig);
int			send(char *s, int pid);
int			ft_strlen(char *str);
long long	ft_atoi(const char *nptr);
void		ft_putchar_fd(char c);
void		ft_putnbr(int n);
void		reset(char *c, int *bit, int *count, int si_pid);
void		handler(int c, siginfo_t *info, void *context);
void		handler_suite(char *print, int *bit, int *count);
#endif