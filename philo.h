/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschreye <jschreye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:52:01 by jschreye          #+#    #+#             */
/*   Updated: 2022/03/31 18:37:31 by jschreye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

typedef struct s_param
{
	int				argc;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	*mutex_sleep;
	pthread_mutex_t	*mutex_thinking;
	pthread_mutex_t	*mutex;
}					t_param;

typedef struct s_philo
{
	long			last_meal;
	int				nb_of_eat;
	long			init_time;
	int				index_philo;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;	
	pthread_t		thread_philo;
	t_param			*param;
}					t_philo;

int		ft_atoi(const char *str);
int		ft_init_struct(char **argv, t_param *param, t_philo *philo);
int		ft_free(t_philo *philo);
void	*ft_routine(void *arg);
t_philo	*ft_init_thread(t_philo *philo, t_param *param);
int		ft_new_tab(t_philo *valeur);
long	get_current_time_ms(void);
int		ft_join(t_philo *tab_philo);

#endif
