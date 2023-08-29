/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:05:30 by etlim             #+#    #+#             */
/*   Updated: 2023/08/29 17:57:01 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		data->philos[i].die_time = data->time_die;
		data->philos[i].eating = 0;
		data->philos[i].status = 0;
		data->philos[i].l_fork = &data->forks[i];
		data->philos[i].r_fork = &data->forks[(i + 1) % (data->philo_num)];
	}
}

int	init_vars(t_data *data, int c, char **str)
{
	data->philo_num = (int) ft_atoi(str[1]);
	data->time_die = (u_int64_t) ft_atoi(str[2]);
	data->time_eat = (u_int64_t) ft_atoi(str[3]);
	data->time_sleep = (u_int64_t) ft_atoi(str[4]);
	if (c == 6)
		data->meal_num = (u_int64_t) ft_atoi(str[5]);
	else
		data->meal_num = 0;
	pthread_mutex_init(&data->lock, NULL);
	pthread_mutex_init(&data->write, NULL);
}
