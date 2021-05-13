/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 23:05:34 by bmarilli          #+#    #+#             */
/*   Updated: 2021/05/11 23:05:35 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

static void *ft_check_live_ph(void *ptr)
{
	t_philo		*philo;
	t_ph_param	*param;

	philo = ptr;
	param = philo->param;
	while (1)
	{
		if (ft_get_time() - philo->time_last_eat - 1 > param->time_to_die)
		{
			param->live = 0;
			ft_print_die(philo);
			sem_post(param->sem_live);
			return (NULL);
		}
		//usleep(1);
	}
	return (NULL);
}

void	ft_take_forks(t_philo *philo)
{
	sem_wait(philo->param->sem_forks);
	ft_print_forks(philo);
	sem_wait(philo->param->sem_forks);
	ft_print_forks(philo);
	ft_print_eating(philo);
	philo->time_last_eat = ft_get_time();
	ft_usleep_fix(philo->param->time_to_eat);
	philo->cnt_eatings++;
	sem_post(philo->param->sem_forks);
	sem_post(philo->param->sem_forks);
	if (philo->param->cnt_eat != -1
		&& philo->cnt_eatings == philo->param->cnt_eat)
		return ;
	ft_philo_sleep(philo);
}

void	*ft_start_philo(void *ptr)
{
	t_philo		*philo;
	pthread_t 	in_live;

	philo = ptr;
	philo->time_last_eat = ft_get_time();
	pthread_create(&in_live, NULL, ft_check_live_ph, ptr);
	ft_take_forks(philo);
	return (NULL);
}
