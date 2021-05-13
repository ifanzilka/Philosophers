/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_live.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 00:51:26 by bmarilli          #+#    #+#             */
/*   Updated: 2021/05/13 00:51:33 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

static int	ft_is_cnt_eat(t_ph_param *param, t_philo *philo)
{
	if (param->cnt_eat == -1)
		return (1);
	if (philo->cnt_eatings != param->cnt_eat)
		return (1);
	return (0);
}

static int	ft_all_end(t_ph_param *param, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < param->num_philo)
	{
		if (philo[i].cnt_eatings != param->cnt_eat)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_die(t_ph_param *param, t_philo *philo)
{
	long	time;

	time = ft_get_time();
	if (time - philo->time_last_eat > param->time_to_die
		&& ft_is_cnt_eat(param, philo))
	{
		return (1);
	}
	return (0);
}

void	*ft_check_live(void *ptr)
{
	t_philo		*arr_philo;
	t_ph_param	*param;
	int			i;

	arr_philo = ptr;
	i = 0;
	param = arr_philo[0].param;
	while (1)
	{
		i = 0;
		while (i < param->num_philo)
		{	
			if (ft_check_die(param, &arr_philo[i]))
			{
				param->live = 0;
				ft_print_die(&arr_philo[i]);
				return (NULL);
			}
			if (ft_all_end(param, arr_philo) == 1)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
