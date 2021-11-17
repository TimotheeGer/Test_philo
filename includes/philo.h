/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:02:27 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/17 00:16:05 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <libc.h>

typedef struct			s_data
{
	pthread_mutex_t		lock;	
	pthread_mutex_t 	*fork;
	int					nb_philo;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	time_t				time_to_start;
	time_t				start;
	int 				count_eat;
	int					dead;
}						t_data;

typedef struct			s_philo
{
	int					id;
	time_t				life;
	time_t				health;
	time_t				time;
	pthread_t 			th;
	pthread_t 			control;
	pthread_mutex_t		eating;
	t_data				*data;
}						t_philo;

void	ft_usleep(time_t t);

t_data	*ft_init_param(int ac, char **av);

int	ft_check_calloc(void *data);

t_philo	*ft_init_philo(int ac, char **av);

void	*ft_calloc(int size);

void	*ft_error(int val, void * data);

time_t	get_time(time_t start);

char		*ft_itoa(int n);


