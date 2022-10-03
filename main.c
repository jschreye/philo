/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:05:04 by grubin            #+#    #+#             */
/*   Updated: 2022/04/05 10:14:32 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_params *params)
{
	free(params->mutex_philo);
	free(params->mutex_sleeping);
	free(params->mutex_thinging);
}

int	ft_check_routine(t_philo *tab_philo, t_params *params, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = 0;
		usleep(100);
		while (i < philo->params->nb_philo)
		{
			if (tab_philo[i].nb_of_eat == 0)
			{
				usleep(100);
				return (1);
			}
			if (current_time() - tab_philo[i].last_meal >= params->time_to_die)
			{
				usleep(100);
				printf("%6ld %d died\n", current_time()
					- tab_philo[i].init_time, i + 1);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

/*int ft_phtread_join(t_philo *tab_philo)
{
	int i;
	void *ret;

	i = 0;
	while (i < tab_philo->params->nb_philo - 1)
	{
		pthread_join(tab_philo[i].thread_philo[i], &ret);
		i++;
	}
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_philo		philo;
	t_params	params;
	t_philo		*tab_philo;

	tab_philo = NULL;
	params.argc = argc;
	philo.params = &params;
	if (params.argc == 5 || params.argc == 6)
	{
		if (ft_init_struct(argv, &philo) == 1)
			return (0);
		tab_philo = ft_init_threads(&philo, &params);
		if (tab_philo == NULL)
			return (0);
		if (ft_check_routine(tab_philo, &params, &philo) == 1)
			ft_free(&params);
	}
	else
		write(1, "error argument", 14);
	return (0);
}
