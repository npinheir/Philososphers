/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:17:08 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/23 12:49:32 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_sleep_think(t_philo *phils)
{
	pthread_mutex_lock(&phils->ru->write);
	ft_print_status("is sleeping ...\n", phils);
	pthread_mutex_unlock(&phils->ru->write);
	ft_usleep(phils->ru->t_sleep);
	
	pthread_mutex_lock(&phils->ru->write);
	ft_print_status("is thinking ...\n", phils);
	pthread_mutex_unlock(&phils->ru->write);

}

static void	ft_eat(t_philo *phils)
{
	pthread_mutex_lock(&phils->r_f);
	pthread_mutex_lock(&phils->ru->write);
	ft_print_status("has taken a fork.\n", phils);
	pthread_mutex_unlock(&phils->ru->write);
	
	pthread_mutex_lock(phils->l_f);
	pthread_mutex_lock(&phils->ru->write);
	ft_print_status("has taken a fork.\n", phils);
	pthread_mutex_unlock(&phils->ru->write);
	
	pthread_mutex_lock(&phils->ru->write);
	ft_print_status("is eating...\n", phils);
	pthread_mutex_unlock(&phils->ru->write);
	phils->nb_eat++;
	ft_usleep(phils->ru->t_eat);
	
	pthread_mutex_unlock(&phils->r_f);
	pthread_mutex_unlock(phils->l_f);
}

static void	*ft_death_checker(void *arg)
{
	t_philo	*phils;

	phils = (t_philo *)arg;
	ft_usleep(phils->ru->t_die + 1);
	if ((phils->ru->start_time - phils->last_eat) > phils->ru->t_die)
	{
		pthread_mutex_lock(&phils->ru->death_mutex);
		phils->ru->death = phils->id;
		pthread_mutex_unlock(&phils->ru->death_mutex);
	}
	return (NULL);
}

static void	*routine(void *arg)
{
	t_philo	*phils;

	phils = (t_philo *)arg;
	if (phils->id % 2 == 0)
		usleep(phils->ru->t_eat / 10);
	
	while (!ft_loop_end(phils) && !ft_death(phils))
	{
		pthread_create(&phils->death_check, NULL, &ft_death_checker, arg);
		ft_eat(phils);
		ft_sleep_think(phils);
		pthread_detach(phils->death_check);
	}
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
	env->rules.death = 0;
	pthread_mutex_init(&env->rules.write, NULL);
	pthread_mutex_init(&env->rules.death_mutex, NULL);
	while (i < env->rules.nb_phil)
	{
		env->phils[i].id = i + 1;
		env->phils[i].nb_eat = 0;
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