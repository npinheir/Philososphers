/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 10:30:41 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/22 14:44:13 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_checkarg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		if (ft_atol(argv[i]) > MAX_INT || ft_atol(argv[i]) < MIN_INT
			|| ft_atol(argv[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_fill_rules(int argc, char **argv, t_env *env)
{
	env->rules.nb_phil = ft_atoi(argv[1]);
	env->rules.t_die = ft_atoi(argv[2]);
	env->rules.t_eat = ft_atoi(argv[3]);
	env->rules.t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		env->rules.cycle = ft_atoi(argv[5]);
	else
		env->rules.cycle = -1;
}

int		ft_errorcheck(int argc, char **argv, t_env *env)
{
	if (ft_checkarg(argv))
		return (1);
	ft_fill_rules(argc, argv, env);
	return (0);
}