/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:02:27 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/01 19:10:46 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <libc.h>

typedef struct		s_philo
{
	long			time;
	int				id;
	pthread_t 		th;
}					t_philo;

typedef struct		s_data
{
	pthread_mutex_t *fork;
	int				nb_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int 			count_eat;
	long			time_milli;
	struct timeval	time;
	t_philo			*philo;
	// t_philo			philo2;
	// t_philo			philo3;
	pthread_mutex_t	fork;

}					t_data;

