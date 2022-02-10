/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:25:48 by tigerber          #+#    #+#             */
/*   Updated: 2021/12/02 13:38:40 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	ft_atoi(const char *nptr)
{
	long int	i;
	long int	res;
	int			neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
	{
		i++;
	}
	if (nptr[i] == '-')
	{
		neg = -1;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10;
		res = res + (nptr[i] - 48);
		i++;
	}
	return (res * neg);
}

int	ft_check_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

int	ft_parse(int ac, char *av[])
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_check_is_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

void	print_ph(char *str, time_t t, t_philo *ph)
{
	pthread_mutex_lock(&ph->data->check_dead);
	if (!ph->data->dead)
		printf(str, t, ph->id + 1);
	pthread_mutex_unlock(&ph->data->check_dead);
}

void	ft_destroy_all(t_philo *ph, t_data *d)
{
	int	i;
	int	nb_ph;

	i = 0;
	nb_ph = d->nb_philo;
	pthread_mutex_destroy(&d->lock);
	pthread_mutex_destroy(&d->control);
	pthread_mutex_destroy(&d->check_dead);
	pthread_mutex_destroy(&d->check_start);
	while (i < nb_ph)
	{
		pthread_mutex_destroy(&d->fork[i]);
		pthread_mutex_destroy(&ph[i].eating);
		i++;
	}
	free(d->fork);
	free(d);
	free(ph);
	return ;
}
