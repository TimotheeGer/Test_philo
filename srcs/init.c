/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:48:50 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/30 16:11:25 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_init_mutex(t_data *d)
{
	pthread_mutex_init(&d->lock, NULL);
	pthread_mutex_init(&d->control, NULL);
	pthread_mutex_init(&d->check_dead, NULL);
	pthread_mutex_init(&d->check_start, NULL);
	return ;
}

t_data	*ft_init_param(int ac, char **av)
{
	t_data	*d;
	int		i;

	i = 0;
	d = ft_calloc(sizeof(t_data));
	if (!ft_check_calloc(d))
		return (NULL);
	d->nb_philo = ft_atoi(av[1]);
	d->time_to_die = ft_atoi(av[2]);
	d->time_to_eat = ft_atoi(av[3]);
	d->time_to_sleep = ft_atoi(av[4]);
	d->count_eat = -1;
	if (ac == 6 && ft_atoi(av[5]) > 0)
		d->count_eat = ft_atoi(av[5]);
	d->fork = ft_calloc(sizeof(pthread_mutex_t) * d->nb_philo);
	if (!ft_check_calloc(d->fork))
		return (NULL);
	while (i < d->nb_philo)
	{
		pthread_mutex_init(&d->fork[i], NULL);
		i++;
	}
	ft_init_mutex(d);
	return (d);
}

t_philo	*ft_init_philo(t_data *d)
{
	int		i;
	int		nb_ph;
	t_philo	*ph;

	nb_ph = d->nb_philo;
	i = 0;
	ph = ft_calloc(sizeof(t_philo) * nb_ph);
	if (!ft_check_calloc(ph))
		return (NULL);
	while (i < nb_ph)
	{
		ph[i].id = i;
		ph[i].data = d;
		pthread_mutex_init(&ph[i].eating, NULL);
		i++;
	}
	return (ph);
}
