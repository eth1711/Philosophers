/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:36:15 by etlim             #+#    #+#             */
/*   Updated: 2023/09/11 07:46:01 by etlim            ###   ########.fr       */
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
	while (get_time_now - start_time < time)
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
