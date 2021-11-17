/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:56:35 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/17 19:21:55 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_one_philo(int ac, char *av[])
{
	if (ac == 6)
	{
		if (ft_atoi(av[5]) == 0)
			return (0);
	}
	if (ft_atoi(av[1]) == 1)
	{
		printf("0 1 has taken a fork.\n");
		printf("%d 1 is dead.\n", ft_atoi(av[2]));
		return (0);
	}
	return (1);
}

void	ft_control(t_philo *ph)
{
	while (!ph->data->dead)
	{
		usleep(1000);
		if (ph->count == 0)
			return ;
		pthread_mutex_lock(&ph->eating);
		if (get_time(0) - ph->life > ph->data->time_to_die)
		{
			ph->data->dead = 1;
			printf("%ld %d id dead.\n", get_time(ph->data->start), ph->id + 1);
			pthread_mutex_unlock(&ph->eating);
			return ;
		}
		pthread_mutex_unlock(&ph->eating);
	}
	return ;
}

void	ft_philo_eat(t_philo *p)
{
	p->count = p->data->count_eat;
	p->life = get_time(0);
	while (!p->data->dead)
	{	
		if (p->count != -1 && p->count-- == 0)
			return ;
		pthread_mutex_lock(&p->data->fork[p->id]);
		print_ph("%ld %d has taken a fork_L.\n", get_time(p->data->start), p);
		pthread_mutex_lock(&p->data->fork[(p->id + 1) % p->data->nb_philo]);
		print_ph("%ld %d has taken a fork_R.\n", get_time(p->data->start), p);
		p->life = get_time(0);
		pthread_mutex_lock(&p->eating);
		print_ph("%ld %d is eating.\n", get_time(p->data->start), p);
		ft_usleep(p->data->time_to_eat);
		pthread_mutex_unlock(&p->eating);
		pthread_mutex_unlock(&p->data->fork[p->id]);
		pthread_mutex_unlock(&p->data->fork[(p->id + 1) % p->data->nb_philo]);
		print_ph("%ld %d is sleeping.\n", get_time(p->data->start), p);
		ft_usleep(p->data->time_to_sleep);
		print_ph("%ld %d is thinking.\n", get_time(p->data->start), p);
	}
	return ;
}

void	start_philo(t_philo *ph)
{
	int	i;

	i = 0;
	ph[0].data->start = get_time(0);
	while (i < ph[0].data->nb_philo)
	{
		pthread_create(&ph[i].th, NULL, (void *)ft_philo_eat, &ph[i]);
		pthread_create(&ph[i].control, NULL, (void *)ft_control, &ph[i]);
		i += 2;
		usleep(50);
	}
	i = 1;
	while (i < ph[0].data->nb_philo)
	{
		pthread_create(&ph[i].th, NULL, (void *)ft_philo_eat, &ph[i]);
		pthread_create(&ph[i].control, NULL, (void *)ft_control, &ph[i]);
		i += 2;
		usleep(50);
	}
	join_philo(ph);
	return ;
}

void	join_philo(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph[0].data->nb_philo)
	{
		pthread_join(ph[i].th, NULL);
		pthread_join(ph[i].control, NULL);
		usleep(50);
		i++;
	}
	return ;
}
