/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:45:03 by bmarilli          #+#    #+#             */
/*   Updated: 2021/05/12 17:01:19 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

void	ft_free_and_destroy(t_philo *arr_philo, t_ph_param *param)
{
	int		i;

	i = 0;
	sem_wait(param->sem_live);
	while (i < param->num_philo)
	{
		kill(arr_philo[i].pid, SIGTERM);
		i++;
	}
	free(arr_philo);
	sem_close(param->sem_forks);
	sem_close(param->sem_print);
	sem_close(param->sem_live);
}
