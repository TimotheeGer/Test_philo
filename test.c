/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:00:08 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/29 15:47:36 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	ft_philo_eat(t_philo *philo)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	philo->time = time.tv_usec;
	printf("0 philo%d take a fork.\n", philo->pos);
	printf("0 philo%d eat.\n", philo->pos);
	while (1)
	{
		gettimeofday(&time, NULL);
		if (philo->time + 300 == time.tv_usec)
		{
			printf("%ld philo%d sleep.\n", time.tv_usec - philo->time, philo->pos);
			break ;
		}
	}
}

int	main(int ac, char *av[])
{
	t_data d;
	
	gettimeofday(&d.time, NULL);
	long time1 = d.time.tv_sec;
	printf("time = %ld\n", time1);
	sleep(2);
	gettimeofday(&d.time, NULL);
	long time2 = d.time.tv_sec;
	printf("time2 = %ld\n", time2);
	printf("time3 = %ld\n", time2 - time1);
	// while (1)
	// {
	// 	gettimeofday(&d.time, NULL);
	// 	if (time2 + 11 == d.time.tv_sec)
	// 	{
	// 		printf("time in while = %ld\n", d.time.tv_sec);
	// 		break ;
	// 	}
	// }
	pthread_t th1;
	pthread_t th2;
	d.philo1.pos = 1;
	pthread_create(&th1 , NULL, (void *)ft_philo_eat, &d.philo1);
	d.philo2.pos = 2;
	pthread_create(&th2 , NULL, (void *)ft_philo_eat, &d.philo2);
	pthread_join(th1 , NULL);
	pthread_join(th2 , NULL);
	return (0);
}