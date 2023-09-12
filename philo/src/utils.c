/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:36:15 by etlim             #+#    #+#             */
/*   Updated: 2023/09/12 18:22:14 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

u_int64_t	get_time_now(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * (u_int64_t)1000 + tv.tv_sec / 1000);
}

void	my_usleep(u_int64_t time)
{
	u_int64_t	start_time;

	start_time = get_time_now();
	while (get_time_now() - start_time < time)
		usleep(100);
}

long	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] != '\0' && str[i] > 47 && str[i] < 58)
	{
		res = (res * 10 + (str[i] - '0'));
		i++;
	}
	return (res * sign);
}

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
	return (1);
}

void	print_message(t_philo *philo, char *message)
{
	if (philo->data->all_alive && philo->data->all_hungry)
	{
		pthread_mutex_lock(&philo->data->write);
		printf("%llu %d %s", get_time_now() - philo->data->time_start,
			philo->index, message);
		if (*message != 'd')
			pthread_mutex_unlock(&philo->data->write);
	}
}
