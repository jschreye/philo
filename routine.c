/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:01:52 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/28 12:01:55 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *ft_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    while (1)
    {
        if (philo->index_philo % 2 != 0)
            usleep(100);
        pthread_mutex_lock(philo->fork_left);
        printf("%d has take a fork left\n", philo->index_philo);
        pthread_mutex_lock(philo->fork_right);
        printf("%d has take a fork right\n", philo->index_philo);
        printf("%d is eating\n", philo->index_philo);
        philo->nb_of_eat--;
        usleep(philo->param->time_to_eat);
        pthread_mutex_unlock(philo->fork_left);
        pthread_mutex_unlock(philo->fork_right);
        printf("%d is sleeping\n", philo->index_philo);
        usleep(philo->param->time_to_sleep);
        printf("%d is thinking\n", philo->index_philo);
    }
}