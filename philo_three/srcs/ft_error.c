/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 03:58:35 by bmarilli          #+#    #+#             */
/*   Updated: 2021/05/11 03:58:37 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

static int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_putstr_fd(char *s, int fd)
{
	if (!(s) || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_errors(int err)
{
	if (err == argv_err)
		ft_putstr_fd("\033[31mArgv_errors\n\033[37m", 2);
	else if (err == parse_err)
		ft_putstr_fd("\033[31mParse_errors\n\033[37m", 2);
	else if (err == pthread_create_err)
		ft_putstr_fd("\033[31mPthread_create_errors\n\033[37m", 2);
	else if (err == pthread_join_err)
		ft_putstr_fd("\033[31mPthread_join_err\n\033[37m", 2);
	else if (err == mutex_init_err)
		ft_putstr_fd("\033[31mMutex_init_err\n\033[37m", 2);
	return (err);
}
