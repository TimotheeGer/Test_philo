/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 13:00:08 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/15 23:11:36 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_ph(char *str, time_t t, t_philo *ph)
{
	(void)t;
	(void)str;
	pthread_mutex_lock(&ph->data->lock);
	// write(1, ft_itoa(t), strlen(ft_itoa(t)));
	// write(1, " ", 1);
	// write(1, ft_itoa(ph->id + 1), strlen(ft_itoa(ph->id + 1)));
	printf(str, t, ph->id + 1);
	pthread_mutex_unlock(&ph->data->lock);
	// usleep(100);
}

void	*ft_philo_eat(t_philo *ph)
{
	// t_philo	*ph;
	int L;
	int R;

	// ph = (t_philo *)philo;
	L = ph->id;
	R = (ph->id + 1) % ph->data->nb_philo;
	while (!ph->data->dead)
	{	
		
		// pthread_mutex_lock(&ph->data->lock_fork);
		pthread_mutex_lock(&ph->data->fork[L]);
		print_ph("-> %ld ph %d has taken a fork_L.\n", get_time(ph->data->start), ph);
		pthread_mutex_lock(&ph->data->fork[R]);
		print_ph("-> %ld ph %d has taken a fork_R.\n", get_time(ph->data->start), ph);
		// pthread_mutex_unlock(&ph->data->lock_fork);
		// pthread_mutex_lock(&ph->eating);

		print_ph("-> %ld ph %d is eating.\n",get_time(ph->data->start), ph);
		ph->life = 1;
		ft_usleep(200);
		// pthread_mutex_unlock(&ph->eating);
		pthread_mutex_unlock(&ph->data->fork[L]);
		pthread_mutex_unlock(&ph->data->fork[R]);
		print_ph("-> %ld ph %d is sleeping.\n", get_time(ph->data->start), ph);
		ft_usleep(200);
		print_ph("-> %ld ph %d is thinking.\n", get_time(ph->data->start), ph);
	}
	return (NULL);
}

void	*ft_control(void *philo)
{
	t_philo *ph;

	ph = (t_philo *)philo;

	while(1)
	{
		ft_usleep(1000);
		printf("test thread philo life = %ld\n", ph->life);
	} 
}

void	start_philo(t_philo *ph)
{
	int i;
	
	i = 0;
	ph[0].data->start = get_time(0);
	while (i < ph[0].data->nb_philo)
	{
		pthread_create(&ph[i].th, NULL, (void *)ft_philo_eat, &ph[i]);
		// usleep(50);
		pthread_create(&ph[i].control, NULL, (void *)ft_control, &ph[i]);
		i+= 2;
		usleep(100);
	}
	i = 1;
	while (i < ph[0].data->nb_philo)
	{
		pthread_create(&ph[i].th, NULL, (void *)ft_philo_eat, &ph[i]);
		// usleep(50);
		i+= 2;
		usleep(100);
	}
	// i = 0;
	// while (i < ph[0].data->nb_philo)
	// {
	// 	
	// 	usleep(50);
	// 	i++;
	// }
	
	i = 0;
	while (i < ph[0].data->nb_philo)
	{
		pthread_join(ph[i].th, NULL);
		usleep(50);
		i++;
	}
	i = 0;
	// while (i < ph[0].data->nb_philo)
	// {
	// 	pthread_join(ph[i].control, NULL);
	// 	usleep(50);
	// 	i++;
	// }
}

void	ft_check_philo(t_philo *ph, char **av)
{
	int i = 0;

	while (i < atoi(av[1]))
	{
		printf("philo id = %d\n", ph[i].id);
		printf("philo adresse = %p\n", &ph[i]);
		printf("philo data nb_philo = %d\n", ph[i].data->nb_philo);
		printf("philo data adress = %p\n", (void*)ph[i].data);
		printf("philo data fork adress = %p\n", &ph[0].data->fork[i]);
		printf("philo data fork adress = %p\n", &ph[0].data->fork[i + 1]);
		printf("philo dead = %d\n", ph[i].data->dead);
		printf("-------------------------------------------\n");
		i++;
		if (i == atoi(av[1]))
			i = 0;
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