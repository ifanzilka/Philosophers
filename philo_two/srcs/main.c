/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 01:12:26 by bmarilli          #+#    #+#             */
/*   Updated: 2021/05/11 03:32:32 by bmarilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philosophers.h"

int	main(int argc, char **argv)
{
	t_philosof	philo;

	if (argc < 4 || argc > 5)
		return (ft_errors(argv_err));
	else
	{
		if (ft_checks(argc, argv) == 1)
			return (ft_errors(parse_err));
		else
		{
			if (ft_parse(argc, argv, &philo) == 1)
				return (ft_errors(parse_err));
		}	
	}
	return (0);
}
