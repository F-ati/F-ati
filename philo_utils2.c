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

void set_bool(pthread_mutex_t *mutex, bool *dest , bool value)
{
    pthread_mutex_lock(mutex);
    *dest = value;
    pthread_mutex_unlock(mutex);
}

bool get_bool(pthread_mutex_t *mutex , bool *value)
{
    bool ret;
    pthread_mutex_lock(mutex);
    ret = *value;
    pthread_mutex_unlock(mutex);
    return(ret);
}

long get_long(pthread_mutex_t *mutex , long *value)
{
    long ret;
    pthread_mutex_lock(mutex);
    ret = *value;
    pthread_mutex_unlock(mutex);
    return(ret);
}

void set_long(pthread_mutex_t *mutex, long *dest , long value)
{
    pthread_mutex_lock(mutex);
    *dest = value;
    pthread_mutex_unlock(mutex);
}

bool simulation_finished(t_data *data)
{
    return(get_bool(&data->data_metex,&data->end_simulation));
}