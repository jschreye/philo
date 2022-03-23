/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:03:00 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/23 16:52:42 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(t_param *param)
{
    int i;
    int val_ret;
    
    i = 0;
    param->mutex = malloc(param->nbr_philo * sizeof(pthread_t));
    if (!param->mutex)
        return (1);
	while (i < param->nbr_philo)
	{
        val_ret = pthread_mutex_init(&param->mutex[i], NULL);
        i++;
    }
    i = 0;
    return (0);
}

int	ft_init_thread(t_philo *philo, t_param *param)
{
    t_philo *struct_tab;
    int val_ret;
    
    philo->index_philo = 0;
    ft_init_mutex(param);
    struct_tab = malloc(philo->param->nbr_philo * sizeof(t_philo));
     if (!struct_tab)
        return (1);
	while (philo->index_philo < philo->param->nbr_philo)
	{
        struct_tab[philo->index_philo].fork_left = &philo->param->mutex[philo->index_philo];
        struct_tab[philo->index_philo].fork_right = &philo->param->mutex[philo->index_philo + 1];
        struct_tab[philo->index_philo].index_philo = philo->index_philo + 1;
        struct_tab[philo->index_philo].param = philo->param;
        val_ret = pthread_create(&philo->thread_philo, NULL, &ft_routine, &struct_tab[philo->index_philo]);
        philo->index_philo++;
    }
    free(struct_tab);
    return (0);
}