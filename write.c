/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-06 21:19:28 by root              #+#    #+#             */
/*   Updated: 2024-12-06 21:19:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//  [time_ms] [philo_id] [action]
// htraed safe 
// write data;

void write_data(t_data *data, int action , bool debug)
{
    long elapsed;
    elapsed = get_time_in_units(1) - data->sim_start_time;
    if(data->philo->full)
        return;
    pthread_mutex_lock(&data->write_mutex);
    if(debug)
        printf("not nessery just for debg\n");
    else
    {
        if((action == 0 || action == 1) && !simulation_finished(data))
            printf("%ld --> %d has taken a fork \n", elapsed , data->philo->id);
        else if (action == 2 && !simulation_finished(data))
            printf("%ld --> %deating\n",elapsed,data->philo->id);
        else if (action == 3 && !simulation_finished(data))
            printf("%ld --> %d sleeping\n",elapsed,data->philo->id);
        else if(action == 4 && !simulation_finished(data))
            printf("%ld -->%d is tenken \n",elapsed,data->philo->id);
        else if (action == 5 && !simulation_finished(data))
            printf("%ld --> %d is died \n",elapsed ,data->philo->id);
    }

    pthread_mutex_unlock(&data->write_mutex);
}
