/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnave <tnave@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:00:08 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/01 17:56:08 by tnave            ###   ########.fr       */
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
	pthread_mutex_lock(philo->fork);
	printf("-> philo%d has taken a fork.\n", philo->id);
	printf("-> philo%d is eating.\n", philo->id);
	ft_usleep(5);
	pthread_mutex_unlock(philo->fork);
}

int	main(int ac, char *av[])
{
	t_data d;;

	(void)ac;
	(void)av;
	memset(&d, 0, sizeof(t_data));
	// printf("id = %d has taken a fork\n");
	int i = 0;
	av[1] = d.nb_philo;

	while (i < d.nb_philo)
	{
		pthread_create(d.philo.th, NULL, ft_philo_eat, &d.philo[i]);
	}
	pthread_mutex_init(&d.fork, NULL);
	pthread_mutex_destroy(&d.fork);
	return (0);
}