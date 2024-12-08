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

    // int i = 0;
    // while(i < data->philo_nb)
    // {
    //     // printf("%d\n",data[i].args.time_must_eat);
    //     // printf("%d\n",data[i].args.time_to_die);
    //     // printf("%d\n",data[i].args.time_to_eat);
    //     // printf("%d\n",data[i].args.time_to_sleep);
    //     // printf("%d\n",*data[i].eat_count);
    //     // printf("%d\n",*data[i].error_occured);
    //     // printf("%d\n",*data[i].still_alive);
    //     // printf("==>%p\n",data[i].multi_lock);
    //     // printf("%ld\n",data[i].last_meal_time);
    //     // printf("%ld\n",data[i].start_time.tv_sec);
    //     // printf("->%d\n",data[i].philo_id);
    //     // printf("%d\n",data[i].philo_nb);

    //     i++;

    // }