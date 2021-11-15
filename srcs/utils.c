/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:42:23 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/15 17:27:05 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_usleep(time_t t)
{
	time_t start;

	start = get_time(0);
	while (1)
	{
		if (get_time(0) - start == t)
			break;
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
	void *data;
	
	data = malloc(size);
	if (!data)
		return (NULL);
	memset(data, 0, size);
	return (data);
}

void	*ft_error(int val, void * data)
{
	if (!data && val == 1)
	{
		write (1, "Error initialization Philo.\n", 29);
		return (NULL);
	}
	return (NULL);
}

time_t	get_time(time_t start)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - start);
}


int			countnum(int n)
{
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*str;
	long	nb;

	nb = n;
	size = countnum(n);
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	while (size-- && nb > 0)
	{
		str[size] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (str);
}
