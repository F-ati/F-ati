/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:36:20 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/11/26 16:36:36 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int verify_args(int ac , char *av[])
{
    int arr[5];
    int i = 1;
    if (ac != 5 && ac != 6)
	{
		printf("philo: usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n");
		return(-7);
	}
    while(av[i] != NULL)
    {
        arr[i - 1] = ft_atoi(av[i]);
        if(check_is_number(av[i]) == 0 )
        {

            printf("philo: invalid input: %s: not a valid unsigned integer between 0 and 2147483647..\n",av[i]);
            return(-7);
        }

        i++;
    }
    if(arr[0] < 0 || arr[0] >= 200)
    {
        printf("philo: invalid input: %d: The number of philosophers must be less than 201.\n" ,arr[0]);
        return(-7);
    }
    if(arr[1] < 60 || arr[2] < 60 || arr[3] < 60 )
    {
        printf("Error: Invalid time value.\n");
        return(-7);
    }
    return(1);
}