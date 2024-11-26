/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-aziz <fel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:04:22 by fel-aziz          #+#    #+#             */
/*   Updated: 2024/11/26 17:35:45 by fel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>

// int main() 
// {
//     struct timeval tv;
//     if (gettimeofday(&tv, NULL) == 0) 
// 	{
//         printf("Seconds: %ld\n", tv.tv_sec);
//         printf("Microseconds: %d\n", tv.tv_usec);
//     } 
// 	else
// 	{
//         perror("gettimeofday failed");
//     }
//     return 0;
// }

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    struct timeval start, end;

    // Record the start time
    gettimeofday(&start, NULL);

    // Perform some task (example: sleep for 2 seconds)
    sleep(2);

    // Record the end time
    gettimeofday(&end, NULL);

    // Calculate the duration in milliseconds
    long seconds = end.tv_sec - start.tv_sec;          // Seconds difference
    long microseconds = end.tv_usec - start.tv_usec;  // Microseconds difference
    long milliseconds = (seconds * 1000) + (microseconds / 1000);

    printf("Duration: %ld milliseconds\n", milliseconds);

    return 0;
}
