/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:50:49 by root              #+#    #+#             */
/*   Updated: 2024/12/09 16:04:48 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eating(t_data *data)
{
	pthread_mutex_lock(data->left_fork);
	write_action(data, "has taken a fork");
	if (data->philo_nb == 1)
	{
		pthread_mutex_unlock(data->left_fork);
		*data->still_alive = 1;
		return ;
	}
	pthread_mutex_lock(data->right_fork);
	write_action(data, "has taken a fork");
	write_action(data, "is eating");
	my_sleep(data->args.time_to_eat);
	pthread_mutex_lock(data->multi_lock);
	*data->eat_count = *data->eat_count + 1;
	data->last_meal_time = get_timestamp_in_ms(data->start_time);
	pthread_mutex_unlock(data->multi_lock);
	pthread_mutex_unlock(data->left_fork);
	pthread_mutex_unlock(data->right_fork);
}

void	run_simulation(t_data *data)
{
	while (1)
	{
		pthread_mutex_lock(data->multi_lock);
		if (*data->error_occured == 1 || *data->still_alive == 1)
		{
			pthread_mutex_unlock(data->multi_lock);
			break ;
		}
		pthread_mutex_unlock(data->multi_lock);
		write_action(data, "is thinking");
		ft_eating(data);
		write_action(data, "is sleeping");
		my_sleep(data->args.time_to_sleep);
		pthread_mutex_lock(data->multi_lock);
		if (data->args.time_must_eat != 0
			&& *(data->eat_count) >= data->args.time_must_eat * data->philo_nb)
		{
			pthread_mutex_unlock(data->multi_lock);
			break ;
		}
		pthread_mutex_unlock(data->multi_lock);
	}
}

void	*routine(void *str)
{
	t_data	*data;

	data = (t_data *)str;
	if (data->philo_id % 2 == 0)
	{
		write_action(data, "is sleeping");
		my_sleep(data->args.time_to_sleep);
	}
	run_simulation(data);
	return (NULL);
}

void	create_threads(t_data *data, pthread_t *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		data[i].left_fork = &forks[i];
		data[i].right_fork = &forks[(i + 1) % data->philo_nb];
		if (pthread_create(&philo[i], NULL, &routine, &data[i]) != 0)
		{
			*data->error_occured = 1;
			printf("Error creating thread: %d\n", data->philo_id);
			return ;
		}
		i++;
	}
}
