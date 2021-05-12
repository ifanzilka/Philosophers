/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:45:03 by bmarilli          #+#    #+#             */
/*   Updated: 2021/05/12 16:45:03 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

void    ft_free_and_destroy(t_philo *arr_philo, t_ph_param *param)
{
    int i;

    i = 0;
    while (i < param->num_philo)
    {
        pthread_mutex_destroy(&param->mutex_forks[i]);
        i++;
    }
    pthread_mutex_destroy(&param->mutex_print);
    free(arr_philo);
}