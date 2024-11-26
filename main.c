/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-26 11:34:12 by root              #+#    #+#             */
/*   Updated: 2024-11-26 11:34:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int verify_args(int ac , char *av[])
{
    int i = 1;
    if (ac != 5 && ac != 6)
	{
		printf("philo: usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]\n");
		return(-7);
	}
    while(av[i] != NULL)
    {
        if(check_is_number(av[i]) == 0)
        {

            printf("philo: invalid input: %s: not a valid unsigned integer between 0 and 2147483647..\n",av[i]);
            return(-7);
        }
        i++;
    }
    
}


int main(int ac , char *av[])
{
    if (verify_args(ac , av) < 0 )
        exit(EXIT_FAILURE);
}