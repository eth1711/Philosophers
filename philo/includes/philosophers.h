/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:00:34 by etlim             #+#    #+#             */
/*   Updated: 2023/09/12 18:14:47 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef struct s_philo
{
	struct s_data	*data;
	int				index;
	int				last_eaten;
	int				num_time_eaten;
	pthread_t		tid;
	pthread_mutex_t	lock;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}		t_philo;

typedef struct s_data
{
	int				philo_num;
	int				meal_num;
	int				all_initiated;
	int				all_alive;
	int				all_hungry;
	t_philo			*philos;
	u_int64_t		time_start;
	u_int64_t		time_die;
	u_int64_t		time_eat;
	u_int64_t		time_sleep;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}		t_data;

void		*routine(void *arg);
void		my_usleep(u_int64_t time);
void		release_forks(t_philo *philo);
void		take_forks(t_philo *philo);
void		print_message(t_philo *philo, char *message);
long		ft_atoi(char *str);
int			check_arg(char **str);
int			init_vars(t_data *data, int c, char **str);
void		init_philos(t_data *data);
int			malloc_data(t_data *data);
u_int64_t	get_time_now(void);

#endif