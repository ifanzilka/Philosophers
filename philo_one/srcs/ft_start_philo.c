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
    long time;

    while(philo->param->fork_status[philo->fork_l] == busy
        || philo->param->fork_status[philo->fork_r] == busy)
        ;
    //ft_usleep_fix(2);
    time = ft_get_time();
    // printf("time :\t\t%ld\n",time);
    // printf("Last eat:\t%ld\n",philo->time_last_eat);
    if (time - philo->time_last_eat > philo->param->time_to_die)
    {
        ft_print_die(philo);
        return ;
    }    
    philo->param->fork_status[philo->fork_l] = busy;
    philo->param->fork_status[philo->fork_r] = busy;    
    pthread_mutex_lock(&philo->param->mutex_forks[philo->fork_l]);
    pthread_mutex_lock(&philo->param->mutex_forks[philo->fork_r]);
    ft_print_forks(philo);
    ft_print_eating(philo);
    ft_usleep_fix(philo->param->time_to_eat);
    philo->time_last_eat = ft_get_time();
    pthread_mutex_unlock(&philo->param->mutex_forks[philo->fork_l]);
    pthread_mutex_unlock(&philo->param->mutex_forks[philo->fork_r]);
    philo->param->fork_status[philo->fork_l] = available;
    philo->param->fork_status[philo->fork_r] = available;
    ft_philo_sleep(philo);
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

    return (NULL);
}
