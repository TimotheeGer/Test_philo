/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:42:23 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/04 18:56:43 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(time_t t)
{
	struct timeval	time;
	long start;
	gettimeofday(&time, NULL);
	start = time.tv_sec;
	// printf("start = %ld\n", start);
	while (1)
	{
		gettimeofday(&time, NULL);
		if (start + t == time.tv_sec)
		{
			// printf("end of start = %ld\n", time.tv_sec);
			break;
		}
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
	void *data;
	
	data = malloc(size);
	if (!data)
		return (NULL);
	memset(data, 0, size);
	return (data);
}
