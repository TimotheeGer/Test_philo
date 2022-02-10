/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:08:47 by tigerber          #+#    #+#             */
/*   Updated: 2021/12/03 12:52:10 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_one_philo(int ac, char *av[])
{
	if (ft_atoi(av[1]) == 0)
	{
		write (1, "Error no philo.\n", 16);
		return (0);
	}
	if (ac == 6)
	{
		if (ft_atoi(av[5]) == 0)
			return (0);
	}
	if (ft_atoi(av[1]) == 1)
	{
		printf("0 1 has taken a fork.\n");
		printf("%ld 1 is died.\n", ft_atoi(av[2]));
		return (0);
	}
	return (1);
}

int	ft_check_control(t_philo *ph)
{
	pthread_mutex_lock(&ph->data->control);
	if (ph->count == 0)
	{
		pthread_mutex_unlock(&ph->data->control);
		return (1);
	}
	pthread_mutex_unlock(&ph->data->control);
	pthread_mutex_lock(&ph->data->check_dead);
	if (ph->data->dead)
	{	
		pthread_mutex_unlock(&ph->data->check_dead);
		return (1);
	}
	pthread_mutex_unlock(&ph->data->check_dead);
	return (0);
}

void	ft_control(t_philo *ph)
{
	while (1)
	{
		usleep(1000);
		if (ft_check_control(ph))
			return ;
		pthread_mutex_lock(&ph->eating);
		if (get_time(0) - ph->life > ph->data->time_to_die)
		{
			pthread_mutex_lock(&ph->data->check_dead);
			ph->data->dead = 1;
			pthread_mutex_unlock(&ph->data->check_dead);
			printf("%ld %d is died.\n", get_time(ph->data->start), ph->id + 1);
			pthread_mutex_unlock(&ph->eating);
			return ;
		}
		pthread_mutex_unlock(&ph->eating);
	}
	return ;
}
