/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:32:26 by tkano             #+#    #+#             */
/*   Updated: 2022/01/17 14:32:37 by tkano            ###   ########.fr       */
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
# include <stdbool.h>

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

bool	arg_parse(t_info *info, int argc, char **argv);
bool    info_init(t_info *info);
bool    philo_init(t_philo *philo, t_info info);
void	grab_fork(t_philo *philo);
void	put_status(t_philo *philo, char *script);

#endif