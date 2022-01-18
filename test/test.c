/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:31:44 by tkano             #+#    #+#             */
/*   Updated: 2022/01/17 12:31:44 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	put_status(t_philo *philo, char *script)
{
	pthread_mutex_lock(philo->print);
	printf("philo %d %s\n", philo->index + 1, script);
	//usleep(5000);
	pthread_mutex_unlock(philo->print);
}

void	eat_philo(t_philo *philo)
{
	if (philo->index %2 == 1)
		usleep(500);
	grab_fork(philo);
	//usleep(15000);
	put_status(philo, "is eating");
	//pthread_detach(philo->th);
}

int	main(int argc, char **argv)
{
	int	i;
	t_philo *philo;
	t_info	info;

	arg_parse(&info, argc, argv);
	info_init(&info);
	i = 0;
	while(i < info.params[0])
	{
		philo = malloc(sizeof(t_philo));
		philo->index = i;
		philo_init(philo, info);
		pthread_create(&(philo->th), NULL, (void *)eat_philo, (void *)philo);
		i++;
	}
	i = 0;
	while(i < info.params[0])
	{
		pthread_mutex_destroy(philo->left);
		pthread_mutex_destroy(philo->right);
		pthread_mutex_destroy(philo->print);
		pthread_join(philo->th, NULL);
		i++;
	}
	return (0);
}