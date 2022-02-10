/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:56:35 by tigerber          #+#    #+#             */
/*   Updated: 2021/12/03 12:50:22 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_check_philo_eat(t_philo *p)
{
	pthread_mutex_lock(&p->data->check_dead);
	if (p->data->dead)
	{
		pthread_mutex_unlock(&p->data->check_dead);
		return (1);
	}
	pthread_mutex_unlock(&p->data->check_dead);
	pthread_mutex_lock(&p->data->control);
	if (p->count != -1 && p->count-- == 0)
	{
		pthread_mutex_unlock(&p->data->control);
		return (1);
	}
	pthread_mutex_unlock(&p->data->control);
	return (0);
}

void	ft_init_count_and_life(t_philo *p)
{	
	pthread_mutex_lock(&p->data->control);
	p->count = p->data->count_eat;
	pthread_mutex_unlock(&p->data->control);
	pthread_mutex_lock(&p->eating);
	p->life = get_time(0);
	pthread_mutex_unlock(&p->eating);
	return ;
}

void	ft_philo_eat(t_philo *p)
{
	ft_init_count_and_life(p);
	while (1)
	{	
		if (ft_check_philo_eat(p))
			return ;
		pthread_mutex_lock(&p->data->fork[p->id]);
		print_ph("%ld %d has taken a fork.\n", get_time(p->data->start), p);
		pthread_mutex_lock(&p->data->fork[(p->id + 1) % p->data->nb_philo]);
		print_ph("%ld %d has taken a fork.\n", get_time(p->data->start), p);
		pthread_mutex_lock(&p->eating);
		p->life = get_time(0);
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
