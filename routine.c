/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:02:17 by grubin            #+#    #+#             */
/*   Updated: 2022/04/01 14:27:02 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	sleep_ms(int ms)
{
	long	start;
	long	curr;

	start = current_time();
	curr = start;
	while (curr < start + ms)
	{
		curr = current_time();
		usleep(200);
	}
}

void	ft_routine_bis(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	printf("%6ld %d  has taken a fork left\n", current_time()
		- philo->init_time, philo->index_philo);
	pthread_mutex_lock(philo->fork_right);
	printf("%6ld %d  has taken a fork right\n", current_time()
		- philo->init_time, philo->index_philo);
	printf("%6ld %d  is eating\n", current_time()
		- philo->init_time, philo->index_philo);
	philo->last_meal = current_time();
	sleep_ms(philo->params->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_lock(philo->params->mutex_sleeping);
	printf("%6ld %d  is sleeping\n", current_time()
		- philo->init_time, philo->index_philo);
	pthread_mutex_unlock(philo->params->mutex_sleeping);
	sleep_ms(philo->params->time_to_sleep);
	pthread_mutex_lock(philo->params->mutex_thinging);
	printf("%6ld %d  is thinking\n", current_time()
		- philo->init_time, philo->index_philo);
	pthread_mutex_unlock(philo->params->mutex_thinging);
	philo->nb_of_eat--;
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->index_philo % 2 == 0)
		usleep(1000);
	while (1)
	{
		if (philo->nb_of_eat == 0)
			break ;
		if (current_time() - philo->last_meal >= philo->params->time_to_die)
			break ;
		ft_routine_bis(philo);
	}
	return (0);
}
