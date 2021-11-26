/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 07:33:24 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/25 10:52:32 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_death_checker(void *arg)
{
	t_philo	*phils;

	phils = (t_philo *)arg;
	ft_usleep(phils->ru->t_die + 1);
	if ((ft_actual_time() - phils->last_eat) >= phils->ru->t_die)
	{
		pthread_mutex_lock(&phils->ru->death_mutex);
		phils->ru->death = phils->id;
		ft_print_status("died :(\n", phils);
		pthread_mutex_unlock(&phils->ru->death_mutex);
		exit(EXIT_SUCCESS);
	}
	return (NULL);
}

static void	*routine(void *arg)
{
	t_philo	*phils;

	phils = (t_philo *)arg;
	if (phils->id % 2 == 0)
		ft_usleep(5);
	while (!ft_loop_end(phils) && !ft_death(phils))
	{
		pthread_create(&phils->death_check, NULL, &ft_death_checker, arg);
		ft_eat(phils);
		ft_sleep_think(phils);
		pthread_detach(phils->death_check);
	}
	return (NULL);
}

int	ft_init_threads(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->rules.nb_phil)
	{
		if (pthread_create(&env->phils[i].th_id, NULL, &routine,
			&env->phils[i]) != 0)
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