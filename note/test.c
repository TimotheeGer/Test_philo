/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:49:31 by tigerber          #+#    #+#             */
/*   Updated: 2021/11/17 18:49:45 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// void	ft_check_philo(t_philo *ph, char **av)
// {
// 	int i = 0;

// 	while (i < atoi(av[1]))
// 	{
// 		printf("philo id = %d\n", ph[i].id + 1);
// 		printf("philo adresse = %p\n", &ph[i]);
// 		printf("philo data nb_philo = %d\n", ph[i].data->nb_philo);
// 		printf("philo data adress = %p\n", (void*)ph[i].data);
// 		printf("philo data fork adress = %p\n", &ph[0].data->fork[i]);
// 		printf("philo data fork adress = %p\n", &ph[0].data->fork[i + 1]);
// 		printf("philo dead = %d\n", ph[i].data->dead);
// 		printf("philo time dead = %ld\n", ph[i].data->time_to_die);
// 		printf("philo time eat = %ld\n", ph[i].data->time_to_eat);
// 		printf("philo time sleep = %ld\n", ph[i].data->time_to_sleep);
// 		printf("philo count_eat = %d\n", ph[i].data->count_eat);
		
// 		printf("-------------------------------------------\n");
// 		i++;
// 	}
// }

//./philo 5 1000 400 200 9