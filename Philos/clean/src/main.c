/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:51:58 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/25 10:25:48 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_lets_play(t_env *env)
{
	if (ft_init_threads(env))
		return (1);
	return (0);
}

static void	ft_init(t_env *env)
{
	size_t	i;

	i = 0;
	env->rules.death = 0;
	env->rules.start_time = ft_actual_time();
	pthread_mutex_init(&env->rules.death_mutex, NULL);
	pthread_mutex_init(&env->rules.write, NULL);
	while (i < env->rules.nb_phil)
	{
		pthread_mutex_init(&env->phils->r_f, NULL);
		env->phils[i].id = i + 1;
		env->phils[i].nb_eat = 0;
		env->phils[i].last_eat = env->rules.start_time;
		env->phils[i].ru = &env->rules;
		env->phils[i].l_f = &env->phils[(i + 1) % env->rules.nb_phil].r_f;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (ft_error_check(argc, argv, &env))
		return (1);
	env.phils = malloc(sizeof(t_philo) * env.rules.nb_phil);
	if (!env.phils)
		return (2);
	ft_init(&env);
	if (ft_lets_play(&env))
	{
		free(env.phils);
		return (3);
	}
	return (0);
}