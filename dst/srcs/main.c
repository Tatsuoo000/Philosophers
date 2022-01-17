/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:41:24 by tkano             #+#    #+#             */
/*   Updated: 2022/01/14 22:31:29 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos = NULL;

	if (!arg_parse(&info, argc, argv))
		return (exit_free(NULL, NULL, "Invalid arguments."));
	if (info_init(&info))
		return (exit_free(&info, NULL, "failed to init infos."));
/*
	if (philos_init(&info, philos))
		return (exit_free(&info, philos, "failed to init philos."));
	start(philos);
*/
	return (exit_free(&info, philos, NULL));
}