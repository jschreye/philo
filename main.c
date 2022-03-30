/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:51:45 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/30 14:27:32 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_routine(t_philo *philo, t_param *param, t_philo *tab_philo)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < philo->param->nbr_philo)
		{
			if (tab_philo[i].nb_of_eat == 0)
				return (0);
			if (get_current_time_ms() - tab_philo[i].last_meal
				>= param->time_to_die)
			{
				printf("%6ld %d died\n", get_current_time_ms()
					- tab_philo[i].init_time, i + 1);
				return (0);
			}
			i++;
		}
	}	
}

int	main(int argc, char **argv)
{
	t_philo	philo;
	t_param	param;
	t_philo	*tab_philo;

	tab_philo = NULL;
	param.argc = argc;
	philo.param = &param;
	if (param.argc == 5 || param.argc == 6)
	{
		if (ft_init_struct(argv, &param, &philo) == 1)
			return (0);
		tab_philo = ft_init_thread(&philo, &param);
		if (tab_philo == NULL)
		{
			ft_free(&philo);
			return (1);
		}
		ft_check_routine(&philo, &param, tab_philo);
	}
	else
		write(1, "Error argument\n", 15);
	ft_free(&philo);
	return (0);
}
