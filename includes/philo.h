/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:02:27 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/04 18:28:24 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <libc.h>

typedef struct			s_do
{
	pthread_mutex_t		*lock;	
}						t_do;

typedef struct			s_philo
{
	int					id;
	int					nb_philo;
	pthread_mutex_t 	*fork_L;
	pthread_mutex_t 	*fork_R;
	pthread_mutex_t		*write;
	pthread_t 			th;
	time_t				time_to_die;
	time_t				time_to_eat;
	time_t				time_to_sleep;
	int 				count_eat;
	long				time;
}						t_philo;

void	ft_usleep(time_t t);

int	ft_init_param(int ac, char **av, t_philo *ph);

int	ft_check_calloc(void *data);

t_philo	*ft_init_philo(char **av);

void	*ft_calloc(int size);



