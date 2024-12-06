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

void wait_all_threads(t_data *data)
{
    while(!get_bool(&data->data_metex,&data->all_threads_ready))
        ;
}

void *dinner_sumulation(void *str)
{
    t_data *data;
    data = (t_data *)str;
    (void)data;
    // spinlock
    wait_all_threads(data);
    // set last meal time;

    while(!simulation_finished(data))
    {
        //1- am i full;
        if(data->philo->full) // to do thread safe;
            break;
        // 2 - eat;
        // eat(data->philo)

        // 3- sleep ->write->status & pricise usleep;

        //4- thinking   
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
        pthread_join(data->philo->thread_id,NULL);
        i++;
    }
    //  if we can reach this line , all phillo are FULL;
}
