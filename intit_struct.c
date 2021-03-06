/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intit_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:03:12 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/31 16:24:24 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_argv(char **argv, t_philo *philo)
{
	int	i;
	int	j;

	i = philo->param->argc - 1;
	while (i > 0)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= 48 && argv[i][j] <= 57)
				j++;
			else
			{
				write (1, "Error: not a number\n", 20);
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
		philo->param->nbr_philo = ft_atoi(argv[1]);
		if (philo->param->nbr_philo == 0)
		{
			write (1, "Error nbr_philo\n", 16);
			return (1);
		}
		philo->param->time_to_die = ft_atoi(argv[2]);
		philo->param->time_to_eat = ft_atoi(argv[3]);
		philo->param->time_to_sleep = ft_atoi(argv[4]);
		if (philo->param->argc == 6)
			philo->nb_of_eat = ft_atoi(argv[5]);
	}
	return (0);
}
