/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:48:50 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/04 18:46:23 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_init_param(int ac, char **av, t_philo *ph)
{
	if (ac == 2)
		ph->nb_philo = atoi(av[1]); // remplace ft_atoi
	else
	{
		write (1, "error param\n", 13);
		return (0);
	}
	return (1);
}

int		test()


t_philo	*ft_init_philo(char **av)
{
	int i;
	int nb_ph;
	t_philo *ph;
	
	i = 0;
	nb_ph = atoi(av[1]);
	ph = ft_calloc(sizeof(t_philo) * nb_ph);
	if (!ft_check_calloc(ph))
		return (0);
	while (i < nb_ph)
	{
		pthread_mutex_init(ph[i].lock, NULL);
		ph[i].id = i + 1;
		ph[i].nb_philo = nb_ph;
		i++;
	}
	return (ph);
}
