/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-05 20:38:29 by root              #+#    #+#             */
/*   Updated: 2024-12-05 20:38:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void eat(t_data *data)
{
    pthread_mutex_lock(&data->philo->first_fork->fork);
    write_data(data,0,0);
    pthread_mutex_lock(&data->philo->second_fork->fork);
    write_data(data,1,0);
    set_long(&data->philo->philo_mutex,&data->philo->last_meals_time,get_time_in_units(1));
    data->philo->meals_counter++;
    write_data(data,2,0);
    pricise_usleep(data,data->time_to_eat);
    if(data->nb_of_meals > 0 && data->philo->meals_counter == data->nb_of_meals )
        set_bool(&data->philo->philo_mutex,&data->philo->full,true);
    pthread_mutex_unlock(&data->philo->first_fork->fork);
    pthread_mutex_unlock(&data->philo->second_fork->fork);

}   

void thinking(t_data *data)
{
    write_data(data,4,0);
}

void wait_all_threads(t_data *data)
{
    while(!get_bool(&data->data_metex,&data->all_threads_ready))
        ;
}

void *dinner_sumulation(void *str)
{
    t_data *data;
    data = (t_data *)str;
    
    // spinlock
    wait_all_threads(data);
    printf("here\n");
    // set last meal time;

    while(!simulation_finished(data))
    {
        //1- am i full;
        if(data->philo->full) // to do thread safe;
            break;
        // 2 - eat; done;
        eat(data);

        // 3- sleep ->write->status & pricise usleep;
        write_data(data,3,0);
        pricise_usleep(data , data->time_to_sleep);
        thinking(data);   
    }
    return(NULL);
}

void   dinner_start(t_data *data)
{
    int i ;
    i = 0;
    if(data->nb_of_meals == -1)
        return;
    else if(data->nb_of_meals == 1)
    {
        // to do;
    }
    else
    {
        while (i < data->nb_of_philo)
        {
            pthread_create(&data->philo[i].thread_id,NULL,&dinner_sumulation,&data);
            // printf("%ld\n",data->philo[i].thread_id);
            i++;
        }
    }
    // start of sumulation;

    data->sim_start_time = get_time_in_units(1);
    // now all tread is ready;
    set_bool(&data->data_metex,&data->all_threads_ready,true);
    //  wait of every one ;
    i = 0;
    while( i < data->nb_of_philo)
    {
        // printf("-->%ld\n",data->philo->thread_id);
        pthread_join(data->philo[i].thread_id,NULL);
        i++;
    }
    //  if we can reach this line , all phillo are FULL;
}
