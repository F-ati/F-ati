/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 22:06:22 by root              #+#    #+#             */
/*   Updated: 2024/12/09 15:56:44 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_data *data, int *i)
{
	if (data[*i].args.time_must_eat != 0
		&& *(data[*i].eat_count) >= data[*i].args.time_must_eat
		* data[*i].philo_nb)
		return (1);
	return (0);
}

int	check_death(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_lock(data[i].multi_lock);
		if (check_meals(data, &i))
		{
			pthread_mutex_unlock(data[i].multi_lock);
			return (1);
		}
		if (get_timestamp_in_ms(data[i].start_time)
			- data[i].last_meal_time >= data[i].args.time_to_die)
		{
			*data[i].still_alive = 1;
			printf("%ld %d died\n", get_timestamp_in_ms(data[i].start_time),
				data[i].philo_id);
			pthread_mutex_unlock(data[i].multi_lock);
			return (1);
		}
		pthread_mutex_unlock(data[i].multi_lock);
		i++;
	}
	return (0);
}

void	check_philo_death(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(data->multi_lock);
		if (*data->error_occured)
		{
			pthread_mutex_unlock(data->multi_lock);
			break ;
		}
		pthread_mutex_unlock(data->multi_lock);
		if (check_death(data))
			break ;
	}
}
