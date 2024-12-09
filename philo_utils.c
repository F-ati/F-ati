/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:21:56 by root              #+#    #+#             */
/*   Updated: 2024/12/09 16:10:20 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	check_is_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+') && str[i + 1] != '\0')
	{
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		i++;
	}
	if (i == ft_strlen(str))
		return (1);
	else
		return (0);
}

void	handle_error_and_exit(char *str)
{
	printf("philo:%s invalid input: 0 and 2147483647..\n", str);
	exit(1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	r;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	r = result * sign;
	if (r < -2147483648 || r > 2147483647)
		handle_error_and_exit(str);
	return ((int)(r));
}

void	my_sleep(useconds_t time)
{
	useconds_t		t;
	struct timeval	start;
	long			current_time;

	t = time * 1000;
	current_time = 0;
	gettimeofday(&start, NULL);
	while (current_time * 1000 < t)
	{
		usleep(50);
		current_time = get_timestamp_in_ms(start);
	}
}
