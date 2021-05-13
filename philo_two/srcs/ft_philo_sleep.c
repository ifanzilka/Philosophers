/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_sleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:58:02 by bmarilli          #+#    #+#             */
/*   Updated: 2021/05/12 13:58:04 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

void	ft_philo_sleep(t_philo *philo)
{
	ft_print_sleep(philo);
	if (philo->param->time_to_sleep > philo->param->time_to_die)
	{
		ft_usleep_fix(philo->param->time_to_die);
		ft_print_die(philo);
		philo->param->live = 0;
		sem_post(philo->param->sem_forks);
		sem_post(philo->param->sem_forks);
		return ;
	}
	else
	{
		ft_usleep_fix(philo->param->time_to_sleep);
		ft_philo_thinking(philo);
	}	
}
