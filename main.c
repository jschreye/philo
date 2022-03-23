/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:51:45 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/23 16:02:42 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_philo philo;
	t_param	param;
	
	param.argc = argc;
	philo.param = &param;
    if (argc == 5 || argc == 6)
	{
		if (ft_init_struct(argv, &param) == 1
		|| ft_init_thread(&philo, &param) == 1)
		{
			ft_free(&philo);
			return (0);
		}
	}
	while(1)
    {
        usleep(65555);
       	exit(0);
	}
	ft_free(&philo);
	return (0);
}