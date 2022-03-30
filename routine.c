/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:01:52 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/30 13:28:31 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	sleep_ms(int ms)
{
	long	start;
	long	curr;

	start = get_current_time_ms();
	curr = start;
	while (curr < start + ms)
	{
		curr = get_current_time_ms();
		usleep(200);
	}
}

void	ft_routine_bis(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	printf("%6ld %d has take a fork left\n", get_current_time_ms()
		- philo->init_time, philo->index_philo);
	pthread_mutex_lock(philo->fork_right);
	printf("%6ld %d has take a fork right\n", get_current_time_ms()
		- philo->init_time, philo->index_philo);
	printf("%6ld %d is eating\n", get_current_time_ms()
		- philo->init_time, philo->index_philo);
	philo->last_meal = get_current_time_ms();
	sleep_ms(philo->param->time_to_eat);
	pthread_mutex_unlock(philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
	printf("%6ld %d is sleeping\n", get_current_time_ms()
		- philo->init_time, philo->index_philo);
	sleep_ms(philo->param->time_to_sleep);
	printf("%6ld %d is thinking\n", get_current_time_ms()
		- philo->init_time, philo->index_philo);
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
			return (0);
		ft_routine_bis(philo);
	}
}
