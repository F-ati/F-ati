/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-05 22:24:45 by root              #+#    #+#             */
/*   Updated: 2024-12-05 22:24:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long	get_timestamp_in_ms(struct timeval start_time)
{
	long			start_ms;
	long			current_ms;
	struct timeval	current_time;
	gettimeofday(&current_time, NULL);
	current_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	start_ms = start_time.tv_sec * 1000 + start_time.tv_usec / 1000;
	return (current_ms - start_ms);
}

void	free_data(t_data *data, pthread_mutex_t *forks, pthread_t *philos)
{
	free(forks);
	free(philos);
	free(data->eat_count);
	free(data->still_alive);
	free(data->error_occured);
	free(data);
}

void	  destroy_mutexes(t_data data, pthread_mutex_t *forks,
		pthread_mutex_t *mutex)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(mutex);
	while (i < data.philo_nb)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	wait_threads(t_data data, pthread_t *philos)
{
	int	i;

	i = 0;
	while (i < data.philo_nb)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
}

void	write_action(t_data *data, char *s)
{
	pthread_mutex_lock(data->multi_lock);
	if (*data->still_alive != 1 && *data->error_occured != 1)
		printf("%ld %d %s\n", get_timestamp_in_ms(data->start_time),
			data->philo_id, s);
	pthread_mutex_unlock(data->multi_lock);
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
