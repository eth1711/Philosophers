/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:00:21 by etlim             #+#    #+#             */
/*   Updated: 2023/09/05 18:54:59 by etlim            ###   ########.fr       */
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

int	main(int c, char **str)
{
	t_data	data;

	if (c != 5 || c != 6)
		// printf("Invalid Number of Arguments!\n");
	if (!check_arg)
		printf("Arguments invalid!\n");

}
