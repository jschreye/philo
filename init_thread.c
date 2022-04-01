/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:03:00 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/31 17:10:55 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(t_param *param)
{
	int	i;
	int	val_ret;

	i = 0;
	param->mutex = malloc(param->nbr_philo * sizeof(pthread_mutex_t));
	param->mutex_sleep = malloc(param->nbr_philo * sizeof(pthread_mutex_t));
	param->mutex_thinking = malloc(param->nbr_philo * sizeof(pthread_mutex_t));
	if (!param->mutex || !param->mutex_sleep || !param->mutex_thinking)
		return (1);
	while (i < param->nbr_philo)
	{
		val_ret = pthread_mutex_init(&param->mutex[i], NULL);
		if (!val_ret)
			return (1);
		val_ret = pthread_mutex_init(&param->mutex_sleep[i], NULL);
		if (!val_ret)
			return (1);
		val_ret = pthread_mutex_init(&param->mutex_thinking[i], NULL);
		if (!val_ret)
			return (1);
		i++;
	}
	return (0);
}

int	ft_init_time(t_philo *tab_philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	tab_philo->last_meal = get_current_time_ms();
	tab_philo->init_time = get_current_time_ms();
	return (0);
}

int	ft_init_fork(t_philo *struct_tab, t_philo *philo)
{
	if (philo->index_philo == philo->param->nbr_philo - 1)
	{
		struct_tab[philo->index_philo].fork_left
			= &philo->param->mutex[philo->index_philo];
		struct_tab[philo->index_philo].fork_right = &philo->param->mutex[0];
	}
	else
	{
		struct_tab[philo->index_philo].fork_left
			= &philo->param->mutex[philo->index_philo];
		struct_tab[philo->index_philo].fork_right
			= &philo->param->mutex[philo->index_philo + 1];
	}
	return (0);
}

void	ft_init_mutex_print(t_philo *tab_philo, t_philo *philo)
{
	tab_philo[philo->index_philo].param->mutex_sleep
		= philo->param->mutex_sleep;
	tab_philo[philo->index_philo].param->mutex_thinking
		= philo->param->mutex_thinking;
}

t_philo	*ft_init_thread(t_philo *philo, t_param *param)
{
	int		val_ret;
	t_philo	*tab_philo;

	philo->index_philo = 0;
	tab_philo = malloc(philo->param->nbr_philo * sizeof(t_philo));
	if (!tab_philo)
		return (NULL);
	ft_init_mutex(param);
	while (philo->index_philo < philo->param->nbr_philo)
	{
		ft_init_time(&tab_philo[philo->index_philo]);
		tab_philo[philo->index_philo].index_philo = philo->index_philo + 1;
		tab_philo[philo->index_philo].param = param;
		tab_philo[philo->index_philo].nb_of_eat = philo->nb_of_eat;
		ft_init_fork(tab_philo, philo);
		ft_init_mutex_print(tab_philo, philo);
		val_ret = pthread_create(&philo->thread_philo,
				NULL, &ft_routine, &tab_philo[philo->index_philo]);
		if (val_ret != 0)
			return (0);
		tab_philo[philo->index_philo].thread_philo = philo->thread_philo;
		philo->index_philo++;
	}
	return (tab_philo);
}
