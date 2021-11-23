/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:17:08 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/22 15:04:08 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *arg)
{
	t_philo	*phils;

	phils = (t_philo *)arg;
	if (phils->id % 2 != 1)
		usleep(100);
	pthread_mutex_lock(&phils->ru->write);
	pthread_mutex_lock(&phils->r_f);
	printf("Hi, I'm philosopher %d and I took the right fork !\n", phils->id);
	pthread_mutex_unlock(&phils->ru->write);
	pthread_mutex_lock(phils->l_f);
	pthread_mutex_lock(&phils->ru->write);
	printf("Hi, I'm philosopher %d and I took the left fork !\n", phils->id);
	pthread_mutex_unlock(&phils->ru->write);
	pthread_mutex_lock(&phils->ru->write);
	printf("Hi, I'm philosopher %d and I am eating ...\n", phils->id);
	pthread_mutex_unlock(&phils->ru->write);
	usleep(phils->ru->t_eat);
	pthread_mutex_unlock(&phils->r_f);
	pthread_mutex_unlock(phils->l_f);
	return (NULL);
}

int	ft_initthreads(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->rules.nb_phil)
	{
		env->phils[i].ru = &env->rules;
		if (pthread_create(&env->phils[i].th_id, NULL, &routine, &env->phils[i]) != 0)
			return (1);
		i++;
	}
	i = 0;
	while (i < env->rules.nb_phil)
	{
		if (pthread_join(env->phils[i++].th_id, NULL) != 0)
			return (1);
	}
	return (0);
}

void	ft_init_phils(t_env *env)
{
	size_t		i;

	i = 0;
	pthread_mutex_init(&env->rules.write, NULL);
	while (i < env->rules.nb_phil)
	{
		env->phils[i].id = i + 1;
		pthread_mutex_init(&env->phils[i].r_f, NULL);
		if (i == 0)
			env->phils[i].l_f = &env->phils[env->rules.nb_phil - 1].r_f;
		else if (i == env->rules.nb_phil - 1)
			env->phils[i].l_f = &env->phils[0].r_f;
		else
			env->phils[i].l_f = &env->phils[i + 1].r_f;
		i++;
	}
}