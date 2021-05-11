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

typedef struct s_philosof
{
	int			num_philo;
	int			num_forks;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			cnt_eat;
}				t_philosof;

enum			 e_errors
{
	argv_err = 1,
	parse_err
}	t_errors;

int		ft_errors(int err);

/*
** Parse
*/

int		ft_checks(int argc, char **argv);
int		ft_isdigit(int ch);
int		ft_atoi(const char *ptr);
int		ft_parse(int argc, char **argv, t_philosof *philo);


#endif
