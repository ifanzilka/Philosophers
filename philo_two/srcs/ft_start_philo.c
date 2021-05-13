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

void	ft_init_forks(t_philo *philo)
{
	if (philo->num == 0)
		philo->fork_l = philo->param->num_philo - 1;
	else
		philo->fork_l = philo->num - 1;
	if (philo->num == philo->param->num_philo - 1)
		philo->fork_r = 0;
	else
		philo->fork_r = philo->num;
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
	t_philo	*philo;

	philo = ptr;
	ft_take_forks(philo);
	return (NULL);
}
