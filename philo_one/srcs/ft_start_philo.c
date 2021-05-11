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

long  ft_get_usec()
{
    t_timeval	timeeval;
    
    gettimeofday(&timeeval, NULL);
    return (timeeval.tv_usec);
}

static void ft_init_forks(t_philo *philo)
{
    if (philo->num  == 0)
        philo->fork_l = philo->param->num_philo - 1;
    else
        philo->fork_l = philo->num - 1;
    if (philo->num == philo->param->num_philo - 1)
        philo->fork_r = 0;
    else
        philo->fork_r = philo->num; 
}

void    ft_take_forks(t_philo *philo)
{
    while(philo->param->fork_status[philo->fork_l] == busy
        || philo->param->fork_status[philo->fork_r] == busy)
        ;
    philo->param->fork_status[philo->fork_l] = busy;
    philo->param->fork_status[philo->fork_r] = busy;    
    pthread_mutex_lock(&philo->param->mutex_forks[philo->fork_l]);
    pthread_mutex_lock(&philo->param->mutex_forks[philo->fork_r]);
    
    ft_print_forks(philo);
    ft_print_eating(philo);
    usleep(philo->param->time_to_eat * 1000);
    pthread_mutex_unlock(&philo->param->mutex_forks[philo->fork_l]);
    pthread_mutex_unlock(&philo->param->mutex_forks[philo->fork_r]);
    philo->param->fork_status[philo->fork_l] = available;
    philo->param->fork_status[philo->fork_r] = available;
}

void    *ft_start_philo(void *ptr)
{
    t_philo *philo;

    philo = ptr;
    ft_init_forks(philo);
    // printf("num thread %d\n", philo->num);
    // printf("l_forks: %d\n",philo->fork_l);
    // printf("r_forks: %d\n",philo->fork_r);
   
    ft_take_forks(philo);
    ft_print_thinking(philo);

    return (NULL);
}
