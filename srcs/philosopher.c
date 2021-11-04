/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:00:08 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/04 18:45:09 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	*ft_philo_eat(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	while (1)
	{
		pthread_mutex_lock(philo->lock);
		
		printf("-> philo %d has taken a fork_L.\n", philo->id);
		printf("-> philo %d has taken a fork_R.\n", philo->id);
		// pthread_mutex_lock(philo[i]->fork);
		// pthread_mutex_lock(philo[i + 1]->fork);
		ft_usleep(2);
		printf("-> philo %d is eating.\n", philo->id);
		ft_usleep(1);
		pthread_mutex_unlock(philo->lock);
		ft_usleep(1);
	}
	return (NULL);
}

void	start_philo(t_philo *ph)
{
	int i = 0;
	printf("test mutex\n");
	pthread_mutex_init(ph[i].lock, NULL);
	while (i < ph->nb_philo)
	{
		pthread_create(&ph[i].th, NULL, (void *)ft_philo_eat, &ph[i]);
		i++;
	}
	i = 0;
	while (i < ph->nb_philo)
	{
		pthread_join(ph[i].th, NULL);
		i++;
	}
}



int	main(int ac, char *av[])
{
	(void)ac;
	t_philo *philo;
	
	// int i = 0;
	philo = NULL;
	
	philo = ft_init_philo(av);
	// memset(philo, 0, sizeof(t_philo));
	// if (!ft_init_param(ac, av , philo))
	// 	return (0);
	ft_check_philo(philo);
	// start_philo(philo);
	// pthread_mutex_init(&d.fork, NULL);
	// pthread_mutex_destroy(&d.fork);
	return (0);
}