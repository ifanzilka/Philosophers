/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_philo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:43:06 by bmarilli          #+#    #+#             */
/*   Updated: 2021/05/11 19:43:08 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"
#include <stdio.h>

static  void ft_wait_thread(int cnt, t_philo *arr_philo)
{
    int i;
    int res;

    i = 0;
    while (i < cnt)
    {
        res = pthread_join(arr_philo[i].thread, NULL);
        if (res != 0)
        {
            ft_errors(pthread_join_err);
            return ;
        }
        i++;
    }
}

static  int ft_init_mutexs(t_mutex *mutex_forks, int cnt,  t_ph_param *ph_param)
{
    int i;
    int res;

    i = 0;
    pthread_mutex_init(&ph_param->mutex_print, NULL);
    while (i < cnt)
    {
        //write(1, "ok\n",3);
        ph_param->fork_status[i] = available;
        res = pthread_mutex_init(&mutex_forks[i], NULL);
        if (res != 0)
            return (ft_errors(mutex_init_err));
        i++;
    }
    return (0);
}

void *print(void *a)
{
    (void)a;
    write(1, "In thread\n", 10);
    return NULL;
}

static int ft_create_threads(t_philo *arr_philo, t_ph_param *ph_param, int cnt)
{
    t_timeval	timeeval;
    int         i;
    int         res;

    gettimeofday(&timeeval, NULL);
    ph_param->start_time = timeeval.tv_usec;
    i = 0;
    while (i < cnt)
    {
        arr_philo[i].param = ph_param;
        arr_philo[i].num = i;
        res = pthread_create(&arr_philo[i].thread, NULL ,/*fun*/ ft_start_philo, &arr_philo[i]);
        if (res != 0)
        {
            return(ft_errors(pthread_create_err));
        }
        i++;
    }
    return (0);
}

void    ft_cr_th_philo(t_ph_param *ph_param)
{
    t_philo *arr_philo;
    int     res;

    //printf("num_ph: %d\n", ph_param->num_philo);
    arr_philo = malloc(sizeof(t_philo) * ph_param->num_philo);
    ph_param->mutex_forks = malloc(sizeof(t_mutex) * ph_param->num_philo);
    ph_param->fork_status = malloc(sizeof(int) * ph_param->num_philo);
    if (ph_param->mutex_forks == NULL || arr_philo == NULL)
        return ;
    res = ft_init_mutexs(ph_param->mutex_forks, ph_param->num_philo, ph_param);
    if (res != 0)
        return ;
    res = ft_create_threads(arr_philo, ph_param, ph_param->num_philo);
    if (res != 0)
        return ;  
    ft_wait_thread(ph_param->num_philo, arr_philo);
}
