/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex-lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:37:30 by tkano             #+#    #+#             */
/*   Updated: 2022/01/17 10:37:30 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void    threadA(int *count);
void    threadB(int *count);
int     shared_resource;
pthread_mutex_t mutex1;

int main(int argc, char **argv){
    pthread_t *t1;
    pthread_t *t2;
    int     i1;
    int     i2;

    shared_resource = 0;
	i1 = argc;
	i2 = atoi(argv[1]);
	t1 = malloc(sizeof(pthread_t));
	t2 = malloc(sizeof(pthread_t));
    pthread_mutex_init(&mutex1, NULL);
    pthread_create(t1, NULL, (void *)threadA, (void *)&i1);
    pthread_create(t2, NULL, (void *)threadB, (void *)&i2);
    pthread_join(*t1, NULL);
    pthread_join(*t2, NULL);
    printf("main(): shared_resource == %d\n", shared_resource);
    return (0);
}

void    threadA(int *count)
{
    int x;
    int i;

    i = 0;
    while (i < *count)
    {
        pthread_mutex_lock(&mutex1);
        x = shared_resource;
        x = x + 1;
        shared_resource = x;
        pthread_mutex_unlock(&mutex1);
        i++;
    }
}

void    threadB(int *count)
{
    int x;
    int i;

    i = 0;
    while(i < *count)
    {
        pthread_mutex_lock(&mutex1);
        x = shared_resource;
        x = x + 1;
        shared_resource = x;
        pthread_mutex_unlock(&mutex1);
        i++;
    }
}
