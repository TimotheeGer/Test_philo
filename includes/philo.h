/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:02:27 by tigerber          #+#    #+#             */
/*   Updated: 2021/12/02 11:51:57 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	pthread_mutex_t	lock;	
	pthread_mutex_t	control;	
	pthread_mutex_t	check_start;	
	pthread_mutex_t	check_dead;	
	pthread_mutex_t	*fork;
	int				nb_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	time_t			time_to_start;
	time_t			start;
	long int		count_eat;
	int				dead;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				count;
	time_t			life;
	time_t			health;
	time_t			time;
	pthread_t		th;
	pthread_t		control;
	pthread_mutex_t	eating;
	t_data			*data;
}				t_philo;

void		ft_usleep(time_t t);

t_data		*ft_init_param(int ac, char **av);

int			ft_check_calloc(void *data);

t_philo		*ft_init_philo(t_data *d);

void		*ft_calloc(int size);

int			ft_error(int val, void *data);

time_t		get_time(time_t start);

long int	ft_atoi(const char *nptr);

int			ft_check_is_digit(char *str);

int			ft_parse(int ac, char *av[]);

int			ft_is_one_philo(int ac, char *av[]);

void		ft_destroy_all(t_philo *ph, t_data *d);

void		print_ph(char *str, time_t t, t_philo *ph);

void		start_philo(t_philo *ph);

void		join_philo(t_philo *ph);

void		ft_init_count_and_life(t_philo *p);

int			ft_check_philo_eat(t_philo *p);

void		ft_philo_eat(t_philo *p);

void		ft_control(t_philo *ph);

int			ft_check_control(t_philo *ph);

#endif