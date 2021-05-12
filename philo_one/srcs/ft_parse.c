/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 04:04:26 by bmarilli          #+#    #+#             */
/*   Updated: 2021/05/11 04:16:11 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

int	ft_isdigit(int ch)
{
	if (ch >= 48 && ch <= 57)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *ptr)
{
	unsigned int	res;
	unsigned int	last_res;
	int				sign;

	res = 0;
	sign = 1;
	while ((9 <= *ptr && *ptr <= 13) || *ptr == 32)
		ptr++;
	if (*ptr == '-')
		sign = -1;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while (ft_isdigit(*ptr))
	{
		last_res = res;
		res = res * 10 + *ptr - '0';
		if (last_res > res)
			return (0);
		ptr++;
	}
	return (res * sign);
}

int	ft_checks(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_parse(int argc, char **argv, t_ph_param *philo)
{
	int	i;

	i = 1;
	philo->cnt_eat = -1;
	while (i < argc)
	{
		if (i == 1)
			philo->num_philo = ft_atoi(argv[i]);
		else if (i == 2)
			philo->time_to_die = ft_atoi(argv[i]);
		else if (i == 3)
			philo->time_to_eat = ft_atoi(argv[i]);
		else if (i == 4)
			philo->time_to_sleep = ft_atoi(argv[i]);
		else if (i == 5)
			philo->cnt_eat = ft_atoi(argv[i]);
		i++;
	}
	if (philo->num_philo < 2 || philo->time_to_die == 0
		|| philo->time_to_eat == 0 || philo->time_to_sleep == 0)
		return (1);
	return (0);
}
