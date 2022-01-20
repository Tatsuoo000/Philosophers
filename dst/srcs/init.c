/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:52:23 by tkano             #+#    #+#             */
/*   Updated: 2022/01/20 21:29:16 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philos_init(t_info *info)
{
	int		i;
	int		num;
	t_philo *philos;

	num = info->params[NUM_OF_PHILOS];
	philos = malloc(sizeof(t_philo) * num);
	i = 0;
	while (philos != NULL && i < num)
	{
		philos[i].info = info;
		philos[i].index = i + 1;
		philos[i].left = &info->forks[i];
		philos[i].right = &info->forks[(i + num -1) % num];
		pthread_mutex_init(&philos[i].access_to_last_meal, NULL);
		philos[i].times_of_finished_meal = 0;
		i++;
	}
	return (philos);
}

bool	info_init(t_info *info)
{
	int	i;
	int	flag;

	i = 0;
	info->forks = malloc(sizeof(pthread_mutex_t) * info->params[NUM_OF_PHILOS]);
	if (info->forks == NULL)
		return (false);
	while (i < info->params[NUM_OF_PHILOS])
	{
		flag = pthread_mutex_init(&info->forks[i], NULL);
		if (flag != 0)
			return (false);
		i++;
	}
	if (pthread_mutex_init(&info->print, NULL))
		return (false);
	info->is_dead = false;
	info->fullfill_num = 0;
	if (info->params[NUM_OF_PHILOS] % 2 == 1)
		info->is_odd = true;
	else
		info->is_odd = false;
	return (true);
}
