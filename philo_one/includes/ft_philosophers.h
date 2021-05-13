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

typedef pthread_mutex_t	t_mutex;
typedef struct s_ph_param
{
	int			live;
	int			num_philo;
	int			num_forks;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			cnt_eat;
	t_mutex		*mutex_forks;
	t_mutex		mutex_print;
	pthread_t	th_in_live;
	int			*fork_status;
	long		start_time;
}				t_ph_param;

typedef struct s_philo
{
	pthread_t	thread;
	t_ph_param	*param;
	int			num;
	int			status;
	int			fork_l;
	int			fork_r;
	long		time_last_eat;
	int			cnt_eatings;
}				t_philo;

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

/*
** Init
*/

void	ft_cr_th_philo(t_ph_param *ph_param);
void	*ft_start_philo(void *ptr);
void	ft_free_and_destroy(t_philo *arr_philo, t_ph_param *param);
long	ft_get_time(void);
void	ft_usleep_fix(long time);

/*
** Print
*/

void	ft_print_forks(t_philo *philo);
void	ft_print_eating(t_philo *philo);
void	ft_print_thinking(t_philo *philo);
void	ft_print_sleep(t_philo *philo);
void	ft_print_die(t_philo *philo);

/*
** Philo
*/

void	ft_take_forks(t_philo *philo);
void	ft_philo_sleep(t_philo *philo);
void	ft_philo_thinking(t_philo *philo);
void	*ft_check_live(void *ptr);

#endif
