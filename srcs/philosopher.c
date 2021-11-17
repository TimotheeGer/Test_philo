/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:00:08 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/17 18:58:53 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char *av[])
{
	t_philo	*philo;
	t_data	*d;

	if (ac == 5 || ac == 6)
	{
		if (!ft_parse(ac, av))
			return (ft_error(1, NULL));
		if (!ft_is_one_philo(ac, av))
			return (0);
		d = ft_init_param(ac, av);
		if (!ft_error(3, d))
			return (0);
		philo = ft_init_philo(d);
		if (!ft_error(4, philo))
			return (0);
		start_philo(philo);
		ft_destroy_all(philo, d);
	}
	else
		return (ft_error(2, NULL));
	return (0);
}
