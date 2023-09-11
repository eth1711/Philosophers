/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:05:30 by etlim             #+#    #+#             */
/*   Updated: 2023/09/11 18:41:37 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_messsage(philo, FORK);
	if (philo->data->philo_num > 1)
		pthread_mutex_lock(philo->r_fork);
	print_messsage(philo, FORK);
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
int	malloc_data(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->philo_num);
	if (!data->philos)
		return (0);
	data->forks = malloc(sizeof(pthread_t) * data->philo_num);
	if (data->forks)
		return (0);
	while (++i < data->philo_num)
		pthread_mutex_init(&data->forks[i], NULL);
	return (1);
}

int	init_philo(t_data *data, int c, char **str)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		data->philos[i].data = data;
		data->philos[i].index = i + 1;
		data->philos[i].last_eaten = get_time_now();
		data->philos[i].num_time_eaten = 0;
		if (i == 0)
		{
			data->philos[i].l_fork = &data->forks[i];
			data->philos[i].r_fork = &data->forks[data->philo_num - 1];
		}
		else
		{
			data->philos[i].l_fork = &data->forks[i];
			data->philos[i].r_fork = &data->forks[i - 1];
		}
	}
}

int	init_vars(t_data *data, int c, char **str)
{
	data->philo_num = (int) ft_atoi(str[1]);
	data->time_die = (u_int64_t) ft_atoi(str[2]);
	data->time_eat = (u_int64_t) ft_atoi(str[3]);
	data->time_sleep = (u_int64_t) ft_atoi(str[4]);
	data->meal_num = 0;
	if (c == 6)
		data->meal_num = (u_int64_t) ft_atoi(str[5]);
	// pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->write, NULL);
	if (!malloc_data(data))
		return (0);
	init_philos(data);
	return (data->philo_num);
}
