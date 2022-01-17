/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:18:25 by tkano             #+#    #+#             */
/*   Updated: 2022/01/17 09:18:25 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

typedef struct func1_arg {
    int x;
}       t_func1_arg;

typedef struct func2_arg{
    int x;
}       t_func2_arg;

void	func1(t_func1_arg *arg)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		printf("func1(%d): %d\n", arg->x, i);
		i++;
	}
}

void	func2(t_func2_arg *arg)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		printf("func2(%d): %d\n", arg->x, i);
		i++;
	}
}

int main()
{
	pthread_t	t1;
	pthread_t	t2;
	t_func1_arg *arg1;
	t_func2_arg *arg2;

	printf("main()\n");
	arg1 = malloc(sizeof(t_func1_arg));
	if (arg1 == NULL)
	{
		perror("no memory for arg1");
		exit (1);
	}
	arg1->x = 10;
	pthread_create(&t1, NULL, (void *)func1, (void *)arg1);
	arg2 = malloc(sizeof(t_func2_arg));
	if (arg2 == NULL)
	{
		perror("no memory for arg2");
		exit (1);
	}
	arg2->x = 20;
	pthread_create(&t2, NULL, (void *)func2, (void *)arg2);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}