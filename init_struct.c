/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:02:25 by grubin            #+#    #+#             */
/*   Updated: 2022/03/31 16:26:30 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_argv(char **argv, t_philo *philo)
{
	int	i;
	int	j;

	i = philo->params->argc - 1;
	while (i > 0)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= 48 && argv[i][j] <= 57)
				j++;
			else
			{
				write(1, "error not a number\n", 19);
				return (1);
			}
		}
		i--;
	}
	return (0);
}

int	ft_init_struct(char **argv, t_philo *philo)
{
	if (ft_check_argv(argv, philo) == 1)
		return (1);
	else
	{
		philo->params->nb_philo = ft_atoi(argv[1]);
		if (philo->params->nb_philo == 0)
		{
			write(1, "error no philo\n", 15);
			return (1);
		}
		philo->params->time_to_die = ft_atoi(argv[2]);
		philo->params->time_to_eat = ft_atoi(argv[3]);
		philo->params->time_to_sleep = ft_atoi(argv[4]);
		if (philo->params->argc == 6)
			philo->nb_of_eat = ft_atoi(argv[5]);
	}
	return (0);
}
