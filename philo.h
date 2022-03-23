/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:52:01 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/23 15:13:00 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
typedef struct s_param
{
	int				argc;
	int				nbr_philo;
	int				nb_of_eat;
	int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
	pthread_mutex_t *mutex;
}			t_param;

typedef struct s_philo
{
	int				index_philo;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;	
	pthread_t		thread_philo;
	t_param			*param;
}					t_philo;

int 	ft_atoi(const char *str);
int 	ft_init_struct(char **argv, t_param *param);
int 	ft_free(t_philo *philo);
void    *ft_routine();
int		ft_init_thread(t_philo *philo, t_param *param);
int		ft_new_tab(t_philo *valeur);


#endif