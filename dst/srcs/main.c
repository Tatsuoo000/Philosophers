/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:41:24 by tkano             #+#    #+#             */
/*   Updated: 2022/01/20 21:52:02 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

bool	start(t_philo *philos)
{
	int		i;
	t_philo *philo;

	i = 0;
	while (i < philos->info->params[NUM_OF_PHILOS])
	{
		philo = &(philos[i]);
		philo = &(philos[i]);
		if (pthread_create(&philo->th, NULL, philo_routine, philo)
			|| pthread_create(&philo->doctor, NULL, doctor_routine, philo))
			return (false);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;

	if (!arg_parse(&info, argc, argv))
		return (exit_free(NULL, NULL, "Invalid arguments."));
	if (!info_init(&info))
		return (exit_free(&info, NULL, "failed to init infos."));
	philos = philos_init(&info);
	if (philos == NULL)
		return (exit_free(&info, philos, "failed to init philos."));
	//start(philos);
	return (exit_free(&info, philos, NULL));
}