/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-29 17:45:54 by root              #+#    #+#             */
/*   Updated: 2024-11-29 17:45:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <pthread.h>
 #include <unistd.h>
#include <stdlib.h>
unsigned long long count = 0;

void *make_coffe(void *str)
{
    (void)str;
    count = count + 1;
    return(NULL);
}

int main()
{
    pthread_t pt1[200000];
    int i = 0;
    int ret;
    while(i < 200000)
    {
        ret = pthread_create(pt1 + i,NULL,make_coffe,NULL);
        if(ret != 0)
            return(printf("error in create thread??\n"));
        i++;    
    }
    i = 0;
    while(i < 200000)
    {
        pthread_join(pt1[i],NULL);
        i++;
    }
printf("%llu\n",count);
}