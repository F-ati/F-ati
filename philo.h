/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:56:40 by root              #+#    #+#             */
/*   Updated: 2024/11/26 16:53:26 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_args
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_must_eat;
}					t_args;

typedef struct s_data
{
	int	*eat_count;
	int	*still_alive;
	int	*error_occured;
	int philo_id;
	int philo_nb;
	long	last_meal_time;
	struct timeval	start_time;
	pthread_mutex_t	*multi_lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
    t_args args;
}t_data;

int	check_is_number(char *str);
int	ft_atoi(char *str);
int verify_args(int ac , char *av[]);
int allocate_data(pthread_mutex_t **forks,pthread_t **philo,t_data **data , char **av);
void initialize_data(t_data *data,char **av , int ac ,pthread_mutex_t *mutex);

long get_time_in_units( int units);
void pricise_usleep(t_data *data , long usec);
long	get_timestamp_in_ms(struct timeval start_time);
int  initialize_mutex(t_data *data,pthread_mutex_t *forks,pthread_mutex_t *mutex);
void	free_data(t_data *data, pthread_mutex_t *forks, pthread_t *philos);
void	  destroy_mutexes(t_data data, pthread_mutex_t *forks,
		pthread_mutex_t *mutex);
void create_threads(t_data *data,pthread_t *philo,pthread_mutex_t *forks);
void	wait_threads(t_data data, pthread_t *philos);
void	my_sleep(useconds_t time);
void	write_action(t_data *data, char *s);
void  ft_eating(t_data *data);
void  check_philo_death(t_data *data);

#endif