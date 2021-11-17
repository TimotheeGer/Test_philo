/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:00:08 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/17 00:53:23 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_ph(char *str, time_t t, t_philo *ph)
{
	pthread_mutex_lock(&ph->data->lock);
	if (!ph->data->dead)
		printf(str, t, ph->id + 1);
	pthread_mutex_unlock(&ph->data->lock);
}

void	ft_philo_eat(t_philo *ph)
{
	ph->life = get_time(0);
	while (!ph->data->dead)
	{	
		pthread_mutex_lock(&ph->data->fork[ph->id]);
		print_ph("%ld %d has taken a fork_L.\n", get_time(ph->data->start), ph);
		pthread_mutex_lock(&ph->data->fork[(ph->id + 1) % ph->data->nb_philo]);
		print_ph("%ld %d has taken a fork_R.\n", get_time(ph->data->start), ph);
		ph->life = get_time(0);
		pthread_mutex_lock(&ph->eating);
		print_ph("%ld %d is eating.\n",get_time(ph->data->start), ph);
		ft_usleep(400);
		pthread_mutex_unlock(&ph->eating);
		pthread_mutex_unlock(&ph->data->fork[ph->id]);
		pthread_mutex_unlock(&ph->data->fork[(ph->id + 1) % ph->data->nb_philo]);
		if (ph->data->dead == 1)
			return ;
		print_ph("%ld %d is sleeping.\n", get_time(ph->data->start), ph);
		ft_usleep(300);
		print_ph("%ld %d is thinking.\n", get_time(ph->data->start), ph);
	}
	return ;
}

void	ft_control(t_philo *ph)
{
	while(!ph->data->dead)
	{
		usleep(1000);
		pthread_mutex_lock(&ph->eating);
		if (get_time(0) - ph->life > 1100)
		{
			ph->data->dead = 1;
			printf("test thread philo %d life = %ld\n", ph->id + 1, get_time(0) - ph->life);
			pthread_mutex_unlock(&ph->eating);
			return ;
		}
		pthread_mutex_unlock(&ph->eating);
		
	}
	return ;
}

void	start_philo(t_philo *ph)
{
	int i;
	
	i = 0;
	ph[0].data->start = get_time(0);
	while (i < ph[0].data->nb_philo)
	{
		pthread_create(&ph[i].th, NULL, (void *)ft_philo_eat, &ph[i]);
		usleep(50);
		pthread_create(&ph[i].control, NULL, (void *)ft_control, &ph[i]);
		i+= 2;
		usleep(50);
	}
	i = 1;
	while (i < ph[0].data->nb_philo)
	{
		pthread_create(&ph[i].th, NULL, (void *)ft_philo_eat, &ph[i]);
		usleep(50);
		pthread_create(&ph[i].control, NULL, (void *)ft_control, &ph[i]);
		i+= 2;
		usleep(50);
	}
	i = 0;
	while (i < ph[0].data->nb_philo)
	{
		pthread_join(ph[i].th, NULL);
		pthread_join(ph[i].control, NULL);
		usleep(50);
		i++;
	}
	return;
}

void	ft_check_philo(t_philo *ph, char **av)
{
	int i = 0;

	while (i < atoi(av[1]))
	{
		printf("philo id = %d\n", ph[i].id + 1);
		printf("philo adresse = %p\n", &ph[i]);
		printf("philo data nb_philo = %d\n", ph[i].data->nb_philo);
		printf("philo data adress = %p\n", (void*)ph[i].data);
		printf("philo data fork adress = %p\n", &ph[0].data->fork[i]);
		printf("philo data fork adress = %p\n", &ph[0].data->fork[i + 1]);
		printf("philo dead = %d\n", ph[i].data->dead);
		printf("-------------------------------------------\n");
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_philo *philo;
	
	philo = ft_init_philo(ac, av);
	if (ft_error(1, philo))
		return (0);
	start_philo(philo);
	
	ft_check_philo(philo, av);
	// time_t time;
	// time_t start;
	// printf("1------------------------------\n"); 
	// start = get_time(0);
	// while (1)
	// {
	// 	time = get_time(0) - start;
	// 	printf("time  = %ld\n", time);
	// 	ft_usleep(300);
	// 	time = get_time(0) - start;
	// 	if (get_time(0) == start + 900)
	// 	{
	// 		printf("is dead at %ld\n", time);
	// 		break;
	// 	}
	// 	printf("time2 = %ld\n", time);
	// 	printf("-----------------------\n"); 
	
	// }
	return (0);
}