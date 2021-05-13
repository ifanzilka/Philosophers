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

static void	ft_wait_thread(int cnt, t_philo *arr_philo)
{
	int	i;
	int	res;

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

static int	ft_create_threads(t_philo *arr_philo, t_ph_param *ph_param, int cnt)
{
	int	i;
	int	res;

	ph_param->start_time = ft_get_time();
	i = 0;
	while (i < cnt)
	{
		arr_philo[i].param = ph_param;
		arr_philo[i].cnt_eatings = 0;
		arr_philo[i].num = i;
		arr_philo[i].time_last_eat = ft_get_time();
		res = pthread_create(&arr_philo[i].thread, NULL,
				ft_start_philo, &arr_philo[i]);
		usleep(10);
		if (res != 0)
		{
			return (ft_errors(pthread_create_err));
		}
		i++;
	}
	pthread_create(&ph_param->th_in_live, NULL, ft_check_live, arr_philo);
	return (0);
}

void	ft_cr_th_philo(t_ph_param *ph_param)
{
	t_philo	*arr_philo;
	int		res;

	ph_param->live = 1;
	arr_philo = malloc(sizeof(t_philo) * ph_param->num_philo);
	ph_param->fork_status = malloc(sizeof(int) * ph_param->num_philo);
	if (arr_philo == NULL)
		return ;
	sem_unlink("/forks");
	sem_unlink("/print");
	ph_param->sem_forks = sem_open("/forks", O_CREAT, 0644,
			ph_param->num_philo);
	ph_param->sem_print = sem_open("/print", O_CREAT, 0644, 1);
	res = ft_create_threads(arr_philo, ph_param, ph_param->num_philo);
	if (res != 0)
		return ;
	ft_wait_thread(ph_param->num_philo, arr_philo);
	ft_free_and_destroy(arr_philo, ph_param);
}
