/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:00:21 by etlim             #+#    #+#             */
/*   Updated: 2023/09/12 18:34:13 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("HI IM PHILO\n");
	// while (!philo->data->all_hungry)
	// 	;
	print_message(philo, THINK);
	if (philo->index % 2 == 0)
		my_usleep(100);
	while (philo->data->all_alive && philo->data->all_hungry)
	{
		take_forks(philo);
		print_message(philo, EAT);
		philo->last_eaten = get_time_now();
		my_usleep(philo->data->time_eat);
		philo->num_time_eaten++;
		release_forks(philo);
		print_message(philo, SLEEP);
		my_usleep(philo->data->time_sleep);
		print_message(philo, THINK);
	}
	return (NULL);
}

void	check_alive(t_data *data)
{
	int			i;
	int			all_full;
	u_int64_t	time_now;

	while (data->all_alive && data->all_hungry)
	{
		i = 0;
		time_now = get_time_now();
		while (data->all_alive && i < data->philo_num)
		{
			if (time_now - data->philos->last_eaten > data->time_die)
			{
				print_message(data->philos, DIED);
				data->all_alive = 0;
			}
			if (data->philos->num_time_eaten < data->meal_num)
				all_full = 0;
			usleep(1);
			i++;
		}
		if (all_full)
			data->all_hungry = 0;
	}
}

int	philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_create(&(data->philos->tid), NULL,
				routine, data->philos) != 0)
			return (1);
		i++;
	}
	data->all_initiated = 1;
	data->time_start = get_time_now();
	check_alive(data);
	i = 0;
	while (i < data->philo_num)
	{
		pthread_join(data->philos->tid, NULL);
		i++;
	}
	return (0);
}

void	free_philo(t_data *data)
{
	int	i;

	i = data->philo_num;
	while (i--)
		pthread_mutex_destroy(&data->forks[i]);
	free (data->forks);
	free (data->philos);
	pthread_mutex_destroy(&data->write);
	free (data);
}

int	main(int c, char **str)
{
	t_data	data;

	if (c < 5 || c > 6)
		printf("Invalid Number of Arguments!\n");
	if (!check_arg(str))
		printf("Arguments invalid!\n");
	if (init_vars(&data, c, str) <= 0)
		printf("Initialization Error");
	if (philos(&data) == 1)
		printf("Failed to create thread");
	free_philo(&data);
	return (0);
}
