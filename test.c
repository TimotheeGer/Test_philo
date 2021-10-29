/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:00:08 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/29 15:13:57 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

// void	ft_philo_eat(t_data *d)
// {
// 	gettimeofday(&d->time, NULL);
// 	d->philo1.time = d->time;
// 	printf("")
// }

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
	while (1)
	{
		gettimeofday(&d.time, NULL);
		if (time2 + 11 == d.time.tv_sec)
		{
			printf("time in while = %ld\n", d.time.tv_sec);
			break ;
		}
	}
	// pthread_t th1;
	// pthread_create(&th1 , NULL, ft_philo_eat, &d);
	// pthread_join(th1 , NULL);
	return (0);
}