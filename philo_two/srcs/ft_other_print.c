/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:28:53 by bmarilli          #+#    #+#             */
/*   Updated: 2021/05/12 00:28:54 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

void	ft_print_forks(t_philo *philo)
{
	long	time;

	if (philo->param->live != 1)
		return ;
	sem_wait(philo->param->sem_print);
	time = ft_get_time();
	printf("%ld\tPhilo %d  has taken a fork\n", time - philo->param->start_time,
		philo->num + 1);
	sem_post(philo->param->sem_print);
}

void	ft_print_eating(t_philo *philo)
{
	long	time;

	if (philo->param->live != 1)
		return ;
	sem_wait(philo->param->sem_print);	
	time = ft_get_time();
	printf("%ld\tPhilo %d  is eating\n", time - philo->param->start_time,
		philo->num + 1);
	sem_post(philo->param->sem_print);	
}

void	ft_print_thinking(t_philo *philo)
{
	long	time;

	if (philo->param->live != 1)
		return ;
	sem_wait(philo->param->sem_print);
	time = ft_get_time();
	printf("%ld\tPhilo %d  is thinking\n", time - philo->param->start_time,
		philo->num + 1);
	sem_post(philo->param->sem_print);	
}

void	ft_print_sleep(t_philo *philo)
{
	long	time;

	if (philo->param->live != 1)
		return ;
	sem_wait(philo->param->sem_print);
	time = ft_get_time();
	printf("%ld\tPhilo %d  is sleep\n", time - philo->param->start_time,
		philo->num + 1);
	sem_post(philo->param->sem_print);	
}

void	ft_print_die(t_philo *philo)
{
	long	time;

	if (philo->param->live != 1)
		return ;
	sem_wait(philo->param->sem_print);	
	time = ft_get_time();
	printf("\033[31m%ld\tPhilo %d died\n\033[37m", time - philo->param->start_time,
		philo->num + 1);
	sem_post(philo->param->sem_print);	
}
