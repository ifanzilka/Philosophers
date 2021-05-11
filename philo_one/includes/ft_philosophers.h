/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 04:02:59 by bmarilli          #+#    #+#             */
/*   Updated: 2021/05/11 04:16:08 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILOSOPHERS_H
# define FT_PHILOSOPHERS_H
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef pthread_mutex_t t_mutex;
typedef struct timeval	t_timeval;
typedef struct s_ph_param
{
	int			num_philo;
	int			num_forks;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			cnt_eat;
	t_mutex		*mutex_forks;
	int			*fork_status;
	t_mutex		mutex_print;
	long		start_time;
}				t_ph_param;

typedef struct s_philo
{
	pthread_t	thread;
	t_ph_param	*param;
	int 		num;
	int			status;
	int			fork_l;
	int 		fork_r;
}				t_philo;

t_philo		*arr_philo;
int			*forks;

enum			 e_status
{
	eating,
	sleeping,
	thinking,
	died
};

enum			 e_errors
{
	argv_err = 1,
	parse_err,
	pthread_create_err,
	pthread_join_err,
	mutex_init_err
};

enum			 e_status_forks
{
	busy,
	available
};

int		ft_errors(int err);

/*
** Parse
*/

int		ft_checks(int argc, char **argv);
int		ft_isdigit(int ch);
int		ft_atoi(const char *ptr);
int		ft_parse(int argc, char **argv, t_ph_param *philo);



void    ft_cr_th_philo(t_ph_param *ph_param);
void    *ft_start_philo(void *ptr);
long  	ft_get_usec();

void    ft_print_forks(t_philo *philo);
void    ft_print_eating(t_philo *philo);
void    ft_print_thinking(t_philo *philo);

#endif
