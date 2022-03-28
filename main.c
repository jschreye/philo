/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:51:45 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/28 12:04:06 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_philo philo;
	t_param	param;
	t_philo *tab_philo;
	
	tab_philo = NULL;
	param.argc = argc;
	philo.param = &param;
    if (argc == 5 || argc == 6)
	{
		if (ft_init_struct(argv, &param, &philo) == 1
		|| ft_init_thread(&philo, &param, tab_philo) == 1)
		{
			ft_free(&philo);
			return (0);
		}
	}
	while(philo.nb_of_eat != 0)
    {
		philo.nb_of_eat--;
		printf("%d\n", philo.nb_of_eat);
	}
	ft_free(&philo);
	return (0);
}