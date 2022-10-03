/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:02:12 by grubin            #+#    #+#             */
/*   Updated: 2022/04/01 11:05:44 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_mutex(t_params *params)
{
	int	i;
	int	err;

	i = 0;
	params->mutex_philo = malloc(params->nb_philo * sizeof(pthread_mutex_t));
	params->mutex_sleeping = malloc(params->nb_philo * sizeof(pthread_mutex_t));
	params->mutex_thinging = malloc(params->nb_philo * sizeof(pthread_mutex_t));
	if (!params->mutex_philo || !params->mutex_sleeping
		|| !params->mutex_thinging)
		return (0);
	while (i < params->nb_philo)
	{
		err = pthread_mutex_init(&params->mutex_philo[i], NULL);
		if (err != 0)
			return (0);
		err = pthread_mutex_init(&params->mutex_sleeping[i], NULL);
		if (err != 0)
			return (0);
		err = pthread_mutex_init(&params->mutex_thinging[i], NULL);
		if (err != 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_init_forks(t_philo *tab_philo, t_philo *philo)
{
	if (philo->index_philo == philo->params->nb_philo - 1)
	{
		tab_philo[philo->index_philo].fork_left
			= &philo->params->mutex_philo[philo->index_philo];
		tab_philo[philo->index_philo].fork_right
			= &philo->params->mutex_philo[0];
	}
	else
	{
		tab_philo[philo->index_philo].fork_left
			= &philo->params->mutex_philo[philo->index_philo];
		tab_philo[philo->index_philo].fork_right
			= &philo->params->mutex_philo[philo->index_philo + 1];
	}
}

void	ft_init_mutex_print(t_philo *tab_philo, t_philo *philo)
{
	tab_philo[philo->index_philo].params->mutex_sleeping
		= philo->params->mutex_sleeping;
	tab_philo[philo->index_philo].params->mutex_thinging
		= philo->params->mutex_thinging;
}

void	ft_init_time(t_philo *tab_philo)
{
	tab_philo->init_time = current_time();
	tab_philo->last_meal = current_time();
}

t_philo	*ft_init_threads(t_philo *philo, t_params *params)
{
	t_philo	*tab_philo;
	int		err;

	philo->index_philo = 0;
	tab_philo = malloc(philo->params->nb_philo * sizeof(t_philo));
	philo->thread_philo = malloc(params->nb_philo * sizeof(pthread_t));
	if (!tab_philo || ft_init_mutex(params) == 0)
		return (NULL);
	while (philo->index_philo < philo->params->nb_philo)
	{
		ft_init_time(&tab_philo[philo->index_philo]);
		tab_philo[philo->index_philo].index_philo = philo->index_philo + 1;
		tab_philo[philo->index_philo].params = params;
		tab_philo[philo->index_philo].nb_of_eat = philo->nb_of_eat;
		ft_init_forks(tab_philo, philo);
		ft_init_mutex_print(tab_philo, philo);
		err = pthread_create(&philo->thread_philo[philo->index_philo], NULL,
				&ft_routine, &tab_philo[philo->index_philo]);
		if (err != 0)
			return (NULL);
		tab_philo[philo->index_philo].thread_philo = philo->thread_philo;
		philo->index_philo++;
	}
	return (tab_philo);
}
