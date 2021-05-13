/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_thinking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:03:36 by bmarilli          #+#    #+#             */
/*   Updated: 2021/05/12 14:03:38 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

void	ft_philo_thinking(t_philo *philo)
{
	if (philo->param->live != 1)
		return ;
	ft_print_thinking(philo);
	ft_take_forks(philo);
}
