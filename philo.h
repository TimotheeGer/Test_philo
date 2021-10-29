/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:02:27 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/29 15:39:40 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <pthread.h>
#include <libc.h>

typedef struct		s_philo
{
	int				fourch;
	long			time;
	int				pos;
	
}					t_philo;

typedef struct		s_data
{
	long			time_milli;
	struct timeval	time;
	t_philo			philo1;
	t_philo			philo2;

}					t_data;

