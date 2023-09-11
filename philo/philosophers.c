/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:00:21 by etlim             #+#    #+#             */
/*   Updated: 2023/09/11 20:09:32 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_arg(char **str)
{
	int	i;
	int	j;

	i = 0;
	if (str[++i] && str[i][0])
	{
		j = -1;
		while (str[i][j++])
		{
			if (str[i][j] >= '0' && str[i][j] <= '9')
				return (0);
		}
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->all_initiated)
		;
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
}

void	print_message(t_philo *philo, char *message)
{
	if (philo->data->all_alive && philo->data->all_hungry)
	{
		pthread_mutex_lock(&philo->data->write);
		printf("%llu %d %s", get_time_now() - philo->data->time_start , philo->index, message);
		if (*message != 'd')
			pthread_mutex_unlock(&philo->data->write);
	}
}
int	main(int c, char **str)
{
	t_data	data;

	if (c != 5 || c != 6)
		printf("Invalid Number of Arguments!\n");
	if (!check_arg)
		printf("Arguments invalid!\n");
	if (init_vars(str, c, &data) <= 0)
		printf("Initialization Error");
	
}
