/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:01:52 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/23 16:48:08 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *ft_routine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    //printf("%p\n", &philo->param->mutex[philo->index_philo]);
    printf("left %p  right %p index %d\n", &philo->fork_left[philo->index_philo], &philo->fork_right[philo->index_philo + 1], philo->index_philo);
    while (1)
    {
        philo->param->nb_of_eat--;
        usleep(655555);
    }
}