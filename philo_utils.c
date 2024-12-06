/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:21:56 by root              #+#    #+#             */
/*   Updated: 2024/11/26 15:56:11 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return(i);
}

int	check_is_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' ) && str[i + 1] != '\0')
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
	printf("philo: invalid input: %s: not a valid unsigned integer between 0 and 2147483647..\n",str);
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

long get_time_in_units( int units)
{
	struct timeval tv;
	int ret = gettimeofday(&tv,NULL);
	if (ret != 0)
		exit(EXIT_FAILURE); // don't forget the remove exit;
	if(units == 0)// second;
	{
		return(tv.tv_sec + (tv.tv_usec / 1000000));
	}
	else if ( units == 1) // millisecond;
	{
		return((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	}
	else if (units == 2) // microsecond;
	{
		return((tv.tv_sec * 1000000) + tv.tv_usec);
	}
	else
		exit(EXIT_FAILURE);
	return(1337);
}

void pricise_usleep(t_data *data , long usec)
{
	long start;
	long elapsed;
	long rem;

	start = get_time_in_units(2);
	while( get_time_in_units(2) - start < usec)
	{
		if(simulation_finished(data))
			break;
		elapsed = get_time_in_units(2) - start;
		rem = usec - elapsed;
		// to get spinlock threshold;
		if( rem > 1000)
			usleep(usec/2);
		else
		{
			// 	SPINLOCK;
			while(get_time_in_units(2) - start < usec)
				;
		}
	}
}