/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:08:34 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/26 11:57:51 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	ft_atoi2(const char *str, int *sign)
{
	int		i;
	size_t	res;

	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			*sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	res;

	sign = 1;
	res = ft_atoi2(str, &sign);
	if (res > __LONG_LONG_MAX__)
	{
		if (sign == 1)
			return (-1);
		if (sign == -1)
			return (0);
	}
	return ((int)res * sign);
}

static long	ft_isdigit(long c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static long	skipuselesschar(const char *str)
{
	long	i;

	i = 0;
	while (str[i] == '\t'
		|| str[i] == '\n'
		|| str[i] == '\v'
		|| str[i] == '\r'
		|| str[i] == '\f'
		|| str[i] == ' ')
		++i;
	return (i);
}

long	ft_atol(const char *str)
{
	long		result;
	long		isneg;
	long		i;

	result = 0;
	i = skipuselesschar(str);
	isneg = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isneg = 1;
		else
			isneg = 0;
		++i;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		++i;
	}
	if (isneg == 1)
		return (result *= -1);
	return (result);
}
