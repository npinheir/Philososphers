/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:51:58 by npinheir          #+#    #+#             */
/*   Updated: 2021/12/06 06:53:11 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_death2(t_env *env)
{
	pthread_mutex_lock(&env->rules.stop_mut);
	if (env->rules.stop)
	{
		pthread_mutex_unlock(&env->rules.stop_mut);
		return (1);
	}
	pthread_mutex_unlock(&env->rules.stop_mut);
	return (0);
}

static void	ft_stop(t_env *env)
{
	int	i;

	i = -1;
	while (!ft_death2(env))
		ft_usleep(1);
	while (++i < (int)env->rules.nb_phil)
		pthread_join(env->phils[i].th_id, NULL);
	pthread_mutex_destroy(&env->rules.write);
	i = -1;
	while (++i < (int)env->rules.nb_phil)
		pthread_mutex_destroy(&env->phils[i].r_f);
	if (env->rules.stop == 2)
		printf("All philosophers ate %d times.\n", env->rules.cycle);
	free(env->phils);
}

static int	ft_lets_play(t_env *env)
{
	if (ft_init_threads(env))
		return (1);
	return (0);
}

static int	ft_init(t_env *env)
{
	size_t	i;

	i = 0;
	env->rules.stop = 0;
	env->rules.start_time = ft_actual_time();
	env->rules.nb_phil_end = 0;
	pthread_mutex_init(&env->rules.write, NULL);
	pthread_mutex_init(&env->rules.stop_mut, NULL);
	pthread_mutex_init(&env->rules.finish, NULL);
	pthread_mutex_init(&env->rules.time_check, NULL);
	while (i < env->rules.nb_phil)
	{
		pthread_mutex_init(&env->phils->r_f, NULL);
		env->phils[i].id = i + 1;
		env->phils[i].nb_eat = 0;
		env->phils[i].finish = 0;
		env->phils[i].last_eat = env->rules.start_time;
		env->phils[i].ru = &env->rules;
		if (env->rules.nb_phil == 1)
			return (1);
		env->phils[i].l_f = &env->phils[(i + 1) % env->rules.nb_phil].r_f;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_env	env;

	if (ft_error_check(argc, argv, &env))
		return (1);
	env.phils = malloc(sizeof(t_philo) * env.rules.nb_phil);
	if (!env.phils)
		return (2);
	if (!ft_init(&env) || ft_lets_play(&env))
	{
		free(env.phils);
		return (0);
	}
	ft_stop(&env);
}
