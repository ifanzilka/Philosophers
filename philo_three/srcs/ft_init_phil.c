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

static void	*ft_wait_thread(void *ph_param)
{
	t_ph_param *param;
	int	i;
	int status;
	int cnt;

	param = ph_param;
	cnt = param->num_philo;
	i = 0;
	while (i < cnt)
	{
		wait(&status);
		i++;
	}
	sem_post(param->sem_live);
	return (NULL);
}

static int ft_create_forks(t_philo *arr_philo, t_ph_param *ph_param)
{
	int		i;
	pid_t pid;

	i = 0;
	ph_param->start_time = ft_get_time();
	while (i < ph_param->num_philo)
	{
		arr_philo[i].num = i;
		arr_philo[i].param = ph_param;
		arr_philo[i].cnt_eatings = 0;
		arr_philo[i].time_last_eat = ft_get_time();
		pid = fork();
		if (pid == 0)
		{
			ft_start_philo(&arr_philo[i]);
			exit(0);
		}
		else
		{
			arr_philo[i].pid = pid;
		}
		usleep(1);
		i++;
	}
	return (1);
}

void	ft_cr_th_philo(t_ph_param *ph_param)
{
	t_philo	*arr_philo;

	ph_param->live = 1;
	arr_philo = malloc(sizeof(t_philo) * ph_param->num_philo);
	ph_param->fork_status = malloc(sizeof(int) * ph_param->num_philo);
	if (arr_philo == NULL)
		return ;
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/live");
	ph_param->sem_forks = sem_open("/forks", O_CREAT, 0644,
			ph_param->num_philo);
	ph_param->sem_print = sem_open("/print", O_CREAT, 0644, 1);
	ph_param->sem_live = sem_open("/live", O_CREAT, 0644, 0);
	ph_param->live = 1;	
	ft_create_forks(arr_philo, ph_param);
	pthread_t lives;
	pthread_create(&lives, NULL, ft_wait_thread, ph_param);
	ft_free_and_destroy(arr_philo, ph_param);
}
