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

int meal = 0;
pthread_mutex_t mutex;
void *fatima1()
{
    int i = 0;
    while (i < 10000000)
    {
        pthread_mutex_lock(&mutex);
        meal ++;
        pthread_mutex_unlock(&mutex);

         i++;

    }
   
}


// int main()
// {
//    pthread_t t1;
//    pthread_t t2;
//    pthread_mutex_init(&mutex,NULL);
//    if (pthread_create(&t1,NULL,fatima1,NULL) != 0)
//         return(3);

//    if(pthread_create(&t2,NULL,fatima1,NULL) != 0 )
//         return(3);
//    if (pthread_join(t1,NULL) != 0)
//         return(3);
//    if (pthread_join(t2,NULL) != 0)
//         return(3);
   
//    pthread_mutex_destroy(&mutex);
//    printf("%d\n",meal);
   
// }