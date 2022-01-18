/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:32:26 by tkano             #+#    #+#             */
/*   Updated: 2022/01/14 22:27:35 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include <errno.h>
# include <stdbool.h>

typedef enum e_arg_index
{
	NUM_OF_PHILOS,
	TIME_TO_DIE,
	TIME_TO_EAT,
	TIME_TO_SLEEP,
	LIMIT_TIMES_TO_DIE,
}	t_arg_index;

typedef struct s_info
{
	int				params[5];
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	bool			is_dead;
	int				fullfill_num;
	bool			is_odd;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	int				index;
	pthread_t		th;
	pthread_t		doctor;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*print;
	pthread_mutex_t	access_to_last_meal;
	long			last_meal_time;
	long			times_of_finished_meal;
}	t_philo;

int		exit_free(t_info *info, t_philo *philos, char *err);
bool	arg_parse(t_info * info, int argc, char **argv);

#endif