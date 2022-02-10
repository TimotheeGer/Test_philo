/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:42:23 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/22 10:45:48 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

time_t	get_time(time_t start)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - start);
}

void	ft_usleep(time_t t)
{
	time_t	start;

	start = get_time(0);
	while (1)
	{
		if (get_time(0) - start >= t)
			break ;
		usleep(200);
	}
}

int	ft_check_calloc(void *data)
{
	if (!data)
	{
		write(1, "Error calloc.\n", 15);
		return (0);
	}
	return (1);
}

void	*ft_calloc(int size)
{
	void	*data;

	data = malloc(size);
	if (!data)
		return (NULL);
	memset(data, 0, size);
	return (data);
}

int	ft_error(int val, void *data)
{
	if (val == 1)
	{
		write (1, "Error Argument Philo is not digits.\n", 37);
		return (0);
	}
	if (val == 2)
	{
		write (1, "Error to much or missing Argument.\n", 36);
		return (0);
	}
	if (!data && val == 3)
	{
		write (1, "Error initialization Data.\n", 28);
		return (0);
	}
	if (!data && val == 4)
	{
		write (1, "Error initialization Philo.\n", 29);
		return (0);
	}
	return (1);
}
