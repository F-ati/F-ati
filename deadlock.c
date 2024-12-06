/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadlock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-03 13:12:15 by root              #+#    #+#             */
/*   Updated: 2024-12-03 13:12:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

typedef struct s_cowbo
{
    char *name;
    pthread_t td;
} t_cowbo;

void *fatima(void *str)
{
  pthread_mutex_init(&mutex1,NULL);
   pthread_mutex_init(&mutex2,NULL);
    t_cowbo *t1;
    t1 = (t_cowbo *)str;
    if(!strcmp(t1->name ,"hello"))
        pthread_mutex_lock(&mutex1);
    else
        pthread_mutex_lock(&mutex2);
    printf("is token his gun\n");
    if(!strcmp(t1->name ,"hello"))
        pthread_mutex_lock(&mutex2);
    else
        pthread_mutex_lock(&mutex1);


return(NULL);
}



int main()
{
    t_cowbo t1;
    t_cowbo t2;
    int ret1, ret2;
    t1.name = "hello";
    t2.name = "wold";
    ret1 = pthread_create(&t1.td,NULL,fatima,&t1);
    ret2 = pthread_create(&t2.td,NULL,fatima,&t1);
    if(ret1 != 0 || ret2 != 0)
        return(printf("error in create a thread\n"));
    pthread_join(t1.td, NULL);
    pthread_join(t2.td,NULL);
    return(0);
}