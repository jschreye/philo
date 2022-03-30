/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intit_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:03:12 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/30 10:57:26 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_argv(char **argv, t_param *param)
{
	int	i;
	int	j;

	i = param->argc - 1;
	while (i > 0)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] >= 48 && argv[i][j] <= 57)
				j++;
			else
				return (1);
		}
		i--;
	}
	return (0);
}

int	ft_init_struct(char **argv, t_param *param, t_philo *philo)
{
	if (ft_check_argv(argv, param) == 1)
		return (1);
	else
	{
		param->nbr_philo = ft_atoi(argv[1]);
		param->time_to_die = ft_atoi(argv[2]);
		param->time_to_eat = ft_atoi(argv[3]);
		param->time_to_sleep = ft_atoi(argv[4]);
		if (param->argc == 6)
			philo->nb_of_eat = ft_atoi(argv[5]);
	}
	return (0);
}
