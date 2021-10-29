/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   note.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigerber <tigerber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:13:39 by tigerber          #+#    #+#             */
/*   Updated: 2021/10/29 14:20:09 by tigerber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Argument du programme = 1 - ./philo 
                        2 - nombre de philosof 
                        3 - (time to die) temp avan de mourir de faim 
                        4 - (time to eat) temp pour manger 
                        5 - (time_to_sleep) temp de dormir 
                        6 - [facultatif](number_of_times_each_philosopher_must_eat)
                                         nombre de fois que chaque philosophe doit manger

3 - time to die en millisecondes sécoule kan le prog et lancer si le philo ne mange pas et sécoule apres avoir manger aussi 

4 - time to eat en millisecondes es le temp quil met pour manger pendan ce temp il a les deux fourchette 

5 - time to sleep en millisecondes es le temp pour dormir 

nombre de philosof = nombre de fourchette 

• Chaque philosophe doit recevoir un numéro de 1 à « nombre_de_philosophes »

• Le philosophe numéro 1 est à côté du numéro de philosophe « nombre_de_philosophes ».
Tout autre philosophe portant le nombre N est assis entre le philosophe N - 1 et
philosophe N+1.

A propos des logs de votre programme :
• Tout changement de statut dun philosophe doit sécrire comme suit (avec X remplacé
avec le numéro de philosophe et timestamp_in_ms lhorodatage actuel en millisecondes) :
◦ timestamp_in_ms X a pris une fourchette
◦ timestamp_in_ms X mange
◦ timestamp_in_ms X dort
◦ timestamp_in_ms X pense
◦ timestamp_in_ms X est mort

pas avoir plus de 10 ms decart entre la mort et le print

• Chaque philosophe doit être un fil.

• Une fourchette entre chaque philosophe, donc sil y a plusieurs philosophes, il y a
sera une fourchette à droite et à gauche de chaque philosophe.

• Pour éviter que les philosophes dupliquent les fourchettes, vous devez protéger létat des fourchettes avec un
mutex pour chacun deux.

philo 1 = mange -> laisse tomber la fourchette -> dormir -> pense

1 millisecondes = 1000 microsecondes

#include <sys/time.h>
#include <pthread.h>
#include <libc.h>

void ft_fonction(t_data *d)
{
    manger 100ms
    dormir 100ms
    penser ???
    mourir 800ms

}

int main(int ac, char *av[])
{
    t_data  d;

    pthread_t th; //memset  ???
    pthread_create(&th, NULL, ft_fonction, &d);
    pthread_join(th , NULL);
    return (0);
)

void    ft_fonction_thread(void)
{
    pthread_mutex_init();
    pthread_mutex_lock();
    pthread_mutex_unlock();
    pthread_mutex_destroy();
}

???
{
    ???
    gettimeofday();
}