/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:34:12 by root              #+#    #+#             */
/*   Updated: 2024/12/09 16:01:08 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_error(int *arr)
{
	if (arr[0] < 0 || arr[0] >= 200)
	{
		printf("philo: nb_of_philo < 201\n");
		return (-7);
	}
	if (arr[1] < 60 || arr[2] < 60 || arr[3] < 60)
	{
		printf("Error: Invalid time value.\n");
		return (-7);
	}
	return (0);
}

int	verify_args(int ac, char *av[])
{
	int	arr[5];
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
	{
		printf("philo: error in args\n");
		return (-7);
	}
	while (av[i] != NULL)
	{
		arr[i - 1] = ft_atoi(av[i]);
		if (check_is_number(av[i]) == 0)
		{
			printf("philo: invalid input:%s: not between 0 and 2147483647..\n ",
				av[i]);
			return (-7);
		}
		i++;
	}
	check_error(arr);
	return (1);
}

int	main(int ac, char *av[])
{
	t_data			*data;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*forks;
	pthread_t		*philo;

	if (verify_args(ac, av) < 0)
		return (1);
	if (allocate_data(&forks, &philo, &data, av) == -1)
	{
		printf("Error: Memory allocation failed\n");
		return (1);
	}
	initialize_data(data, av, ac, &mutex);
	if (initialize_mutex(data, forks, &mutex) == -1)
	{
		free_data(data, forks, philo);
		destroy_mutexes(*data, forks, &mutex);
		return (1);
	}
	create_threads(data, philo, forks);
	check_philo_death(data);
	wait_threads(*data, philo);
	free_data(data, forks, philo);
	destroy_mutexes(*data, forks, &mutex);
}
