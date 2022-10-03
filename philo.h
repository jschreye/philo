/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grubin <grubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:05:46 by grubin            #+#    #+#             */
/*   Updated: 2022/04/01 11:07:06 by grubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_params
{
	int				argc;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*mutex_philo;
	pthread_mutex_t	*mutex_sleeping;
	pthread_mutex_t	*mutex_thinging;
}					t_params;

typedef struct s_philo
{
	long			last_meal;
	int				nb_of_eat;
	long			init_time;
	int				index_philo;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_t		*thread_philo;
	t_params		*params;
}					t_philo;

int					ft_atoi(const char *str);
int					ft_init_struct(char **argv, t_philo *philo);
t_philo				*ft_init_threads(t_philo *philo, t_params *params);
void				*ft_routine(void *arg);
long				current_time(void);
void				sleep_ms(int ms);
int					ft_phtread_join(t_philo *tab_philo);

#endif
