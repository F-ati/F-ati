/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:07:27 by root              #+#    #+#             */
/*   Updated: 2024/12/09 14:28:09 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	allocate_data(pthread_mutex_t **forks, pthread_t **philo, t_data **data,
		char **av)
{
	int	nb_philo;

	nb_philo = ft_atoi(av[1]);
	*data = malloc(sizeof(t_data) * nb_philo);
	if (*data == NULL)
		return (-1);
	*forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	if (*forks == NULL)
	{
		free(*data);
		return (-1);
	}
	*philo = malloc(sizeof(pthread_t) * nb_philo);
	if (*philo == NULL)
	{
		free(*data);
		free(*forks);
		return (-1);
	}
	return (0);
}

void	init_args(t_data *data, char **av, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		data[i].args.time_must_eat = 0;
		data[i].args.time_to_die = ft_atoi(av[2]);
		data[i].args.time_to_eat = ft_atoi(av[3]);
		data[i].args.time_to_sleep = ft_atoi(av[4]);
		data[i].philo_nb = ft_atoi(av[1]);
		data[i].philo_id = i + 1;
		gettimeofday(&data[i].start_time, NULL);
		data[i].last_meal_time = get_timestamp_in_ms(data[i].start_time);
		i++;
	}
}

void	set_char_data(t_data *data, pthread_mutex_t *mutex)
{
	int	i;
	int	*p1;
	int	*p2;
	int	*p3;

	p1 = malloc(sizeof(int));
	p2 = malloc(sizeof(int));
	p3 = malloc(sizeof(int));
	*p1 = 0;
	*p2 = 0;
	*p3 = 0;
	i = 0;
	while (i < data->philo_nb)
	{
		data[i].eat_count = p1;
		data[i].error_occured = p2;
		data[i].still_alive = p3;
		data[i].multi_lock = mutex;
		i++;
	}
}

void	initialize_data(t_data *data, char **av, int ac, pthread_mutex_t *mutex)
{
	int	nb_philo;
	int	i;

	i = 0;
	nb_philo = ft_atoi(av[1]);
	init_args(data, av, nb_philo);
	set_char_data(data, mutex);
	while (ac == 6 && i < data->philo_nb)
	{
		data[i].args.time_must_eat = ft_atoi(av[5]);
		i++;
	}
}

int	initialize_mutex(t_data *data, pthread_mutex_t *forks,
		pthread_mutex_t *mutex)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		printf("Error initializing mutex\n");
		return (-1);
	}
	while (i < data->philo_nb)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			printf("Error initializing mutex\n");
			return (-1);
		}
		i++;
	}
	return (1);
}
