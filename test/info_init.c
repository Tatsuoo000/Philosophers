/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:57:55 by tkano             #+#    #+#             */
/*   Updated: 2022/01/17 12:57:55 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

bool	arg_parse(t_info *info, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		info->params[i - 1] = atoi(argv[i]);
		i++;
	}
	return (true);
}

bool    info_init(t_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof (pthread_mutex_t) * info->params[0]);
	while(i < info->params[0])
	{
		pthread_mutex_init(&(info->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&(info->print), NULL);
	info->is_dead = false;
	info->fullfill_num = -1;
	info->is_dead = false;
	return (true);
}
