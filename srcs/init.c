/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:48:50 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/15 17:13:09 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_data	*ft_init_param(int ac, char **av)
{
	t_data	*d;
	int		i;

	i = 0;
	d = ft_calloc(sizeof(t_data));
	if (!ft_check_calloc(d))
		return (NULL);
	if (ac == 2)
		d->nb_philo = atoi(av[1]); // remplace ft_atoi
	else
		ft_error(0, NULL);
	d->fork = ft_calloc(sizeof(pthread_mutex_t) * d->nb_philo);
	if (!ft_check_calloc(d->fork))
		return (NULL);
	while (i < d->nb_philo)
	{
		pthread_mutex_init(&d->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&d->lock, NULL);
	pthread_mutex_init(&d->lock_fork, NULL);
	return (d);
}


t_philo	*ft_init_philo(int ac, char **av)
{
	int i;
	int nb_ph;
	t_philo *ph;
	t_data	*d;

	nb_ph = atoi(av[1]);// remplace ft_atoi
	i = 0;
	ph = ft_calloc(sizeof(t_philo) * nb_ph);
	if (!ft_check_calloc(ph))
		return (NULL);
	d = ft_init_param(ac, av);
	while (i < nb_ph) 
	{
		ph[i].id = i;
		ph[i].data = d;
		pthread_mutex_init(&ph[i].eating, NULL);	
		i++;
	}
	return (ph);
}
