/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 07:46:55 by tkano             #+#    #+#             */
/*   Updated: 2022/01/14 22:25:18 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *str)
{
	size_t	ret;

	ret = 0;
	while (str[ret] != '\0')
		ret++;
	return (ret);
}

bool	ft_isdigit(char *str)
{
	if (!str || !*str)
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

long long	ft_atoll(const char *str)
{
	long long	num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	return (num);
}


bool	arg_parse(t_info * info, int argc, char **argv)
{
	int			i;
	long long	tmp;

	if (!(argc == 5 || argc == 6))
		return (false);
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 10 || !ft_isdigit(argv[i]))
			return (false);
		tmp = ft_atoll(argv[i]);
		if (tmp <= 0 || tmp > INT_MAX)
			return (false);
		info->params[i - 1] = tmp;
		i++;
	}
	if (argc == 5)
		info->params[LIMIT_TIMES_TO_DIE] = -1;
	return (true);
}
