/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:41:17 by tkano             #+#    #+#             */
/*   Updated: 2022/01/17 13:41:17 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	grab_fork(t_philo *philo)
{
	//usleep(40);
	pthread_mutex_lock(philo->left);
	pthread_mutex_lock(philo->right);
	put_status(philo, "has taken a fork");
	usleep(15000);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	//put_status(philo, "is laving");
	//usleep(5000);
}

bool    philo_init(t_philo *philo, t_info info)
{
	philo->left = &(info.forks[philo->index]);
	//printf("philo%d, left hand: %d\n", philo->index + 1, (philo->index + info.params[0] - 1) % (info.params[0]));
	//printf("philo%d, right hand: %d\n", philo->index + 1, (philo->index + info.params[0] - 1) % (info.params[0]));
	philo->right = &(info.forks[(philo->index + info.params[0] - 1) % (info.params[0])]);
	philo->print = &(info.print);
}