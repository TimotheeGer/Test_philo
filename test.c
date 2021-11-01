/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:00:08 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/01 19:15:50 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	ft_usleep(time_t t)
{
	struct timeval	time;
	long start;
	gettimeofday(&time, NULL);
	start = time.tv_sec;
	printf("start = %ld\n", start);
	while (1)
	{
		gettimeofday(&time, NULL);
		if (start + t == time.tv_sec)
		{
			printf("end of start = %ld\n", time.tv_sec);
			break;
		}
	}
}

void	ft_philo_eat(t_philo *philo)
{
	printf("-> philo %d has taken a fork.\n", philo->id);
	printf("-> philo %d has taken a fork.\n", philo->id);
	// pthread_mutex_lock(philo[i]->fork);
	// pthread_mutex_lock(philo[i + 1]->fork);
	ft_usleep(3);
	printf("-> philo %d is eating.\n", philo->id);
	// pthread_mutex_unlock(philo->fork);
}

void	*ft_calloc(int size)
{
	void *data;
	
	data = malloc(size);
	if (!data)
		return (NULL);
	memset(data, 0, size);
	return (data);
}

void	init_philo(t_data *d)
{
	int i;

	i = 1;
	
	d->philo = ft_calloc(sizeof(d->philo) * d->nb_philo);
	d->fork = ft_calloc(sizeof(pthread_mutex_t) * d->nb_philo);
	
	
	while (i <= d->nb_philo)
	{
		pthread_create(&d->philo[i].th, NULL, (void *)ft_philo_eat, &d->philo[i]);
		d->philo[i].id = i;
		i++;
	}
	i = 1;
	while (i <= d->nb_philo)
	{
		pthread_join(d->philo[i].th, NULL);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_data d;

	(void)ac;
	memset(&d, 0, sizeof(t_data));
	// printf("id = %d has taken a fork\n");
	//init parametre//
	d.nb_philo = atoi(av[1]); // remplace ft_atoi
	//				//
	//init philo 	//
	init_philo(&d);

	// pthread_mutex_init(&d.fork, NULL);
	// pthread_mutex_destroy(&d.fork);
	return (0);
}