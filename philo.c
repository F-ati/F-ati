/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 23:50:49 by root              #+#    #+#             */
/*   Updated: 2024-11-25 23:50:49 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void assign_forks(t_data *data , t_philo philo, int philo_position)
{
    philo.first_fork = &data->forks[(philo_position + 1) % data->nb_of_philo];
    philo.second_fork = &data->forks[philo_position ];

    if(philo.id % 2 == 0)
    {
        philo.first_fork = &data->forks[philo_position];
        philo.second_fork = &data->forks[(philo_position + 1) % data->nb_of_philo];
    }
    
}

void init_philo(t_data *data)
{
    int i = 0;
    while(i < data->nb_of_philo)
    {
        data->philo[i].id = i + 1;
        data->philo[i].full = false;
        data->philo[i].meals_counter = 0;
        pthread_mutex_init(&data->philo->philo_mutex,NULL);
        assign_forks(data,data->philo[i], i);
        i++;
    }
}

void init_forks(t_data *data)
{
    int i = 0;
    while(i < data->nb_of_philo)
    {
        pthread_mutex_init(&data->forks[i].fork,NULL);
        data->forks[i].fork_id = i;
        i++;
    }
}


void initialize_data(t_data *data,char **av)
{
    data->nb_of_philo = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]) * 1000;
    data->time_to_eat = ft_atoi(av[3]) * 1000;
    data->time_to_sleep = ft_atoi(av[4]) * 1000;
    if(av[5] != NULL)
        data->nb_of_meals = ft_atoi(av[5]);
    else
        data->nb_of_meals = -1;
    data->end_simulation = false;
    data->all_threads_ready = false;
    data->philo = malloc(sizeof(t_philo) * data->nb_of_philo);
    if(data->philo ==   NULL)
        exit(EXIT_FAILURE);
     pthread_mutex_init(&data->data_metex,NULL);
     pthread_mutex_init(&data->write_mutex,NULL); 
    data->forks = malloc(sizeof(t_forks) * data->nb_of_philo);
    if(data->forks == NULL)
        exit(EXIT_FAILURE);
    init_forks(data);
    init_philo(data);

}