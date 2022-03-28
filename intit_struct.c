/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intit_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:03:12 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/28 12:01:04 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_struct(char **argv, t_param *param, t_philo *philo)
{
    param->nbr_philo = ft_atoi(argv[1]);
    param->time_to_die = ft_atoi(argv[2]);
    param->time_to_eat = ft_atoi(argv[3]);
    param->time_to_sleep = ft_atoi(argv[4]);
    if (param->argc == 6)
        philo->nb_of_eat = ft_atoi(argv[5]);
    return (0);
}