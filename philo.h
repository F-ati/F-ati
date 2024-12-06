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
#include <stdbool.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_forks
{
    pthread_mutex_t  fork; // this is the a metux;
    int fork_id;

}t_forks;

typedef struct s_philo
{
    int id ;
    long meals_counter;
    bool full;
    long last_meals_time;
    t_forks *first_fork;
    t_forks *second_fork;
    pthread_mutex_t philo_mutex;//usefull for race_condition;
    pthread_t thread_id; // a philo is a thread;

}t_philo;

typedef struct s_data
{
    long nb_of_philo;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long nb_of_meals;
    long sim_start_time;
    bool end_simulation ;// a philo dies or all philo full;
    bool all_threads_ready;
    pthread_mutex_t data_metex; // avoid race while reading from table;
    pthread_mutex_t write_mutex;
    t_forks *forks;
    t_philo *philo;

}t_data;

int	check_is_number(char *str);
int	ft_atoi(char *str);
int verify_args(int ac , char *av[]);
void initialize_data(t_data *data,char **arv);
void   dinner_start(t_data *data);
void   dinner_start(t_data *data);
bool simulation_finished(t_data *data);
void set_long(pthread_mutex_t *mutex, long *dest , long value);
long get_long(pthread_mutex_t *mutex , long *value);
bool get_bool(pthread_mutex_t *mutex , bool *value);
void set_bool(pthread_mutex_t *mutex, bool *dest , bool value);
void wait_all_threads(t_data *data);
long get_time_in_units( int units);
void pricise_usleep(t_data *data , long usec);
void write_data(t_data *data, int action , bool debug);

#endif