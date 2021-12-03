/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 07:33:24 by npinheir          #+#    #+#             */
/*   Updated: 2021/12/02 12:29:14 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death(t_philo *phils, int n)
{
	pthread_mutex_lock(&phils->ru->stop_mut);
	if (n)
		phils->ru->stop = n;
	if (phils->ru->stop)
	{
		pthread_mutex_unlock(&phils->ru->stop_mut);
		return (1);
	}
	pthread_mutex_unlock(&phils->ru->stop_mut);
	return (0);
}

static void	*ft_is_dead(void *arg)
{
	t_philo	*phils;

	phils = (t_philo *)arg;
	ft_usleep(phils->ru->t_die + 1);
	pthread_mutex_lock(&phils->ru->time_check);
	pthread_mutex_lock(&phils->ru->finish);
	if (!ft_death(phils, 0) && !phils->finish && (ft_actual_time() - phils->last_eat >= phils->ru->t_die))
	{
		pthread_mutex_unlock(&phils->ru->time_check);
		pthread_mutex_unlock(&phils->ru->finish);
		pthread_mutex_lock(&phils->ru->write);
		ft_print_status("died.\n", phils);
		pthread_mutex_unlock(&phils->ru->write);
		ft_death(phils, 1);
	}
	pthread_mutex_unlock(&phils->ru->time_check);
	pthread_mutex_unlock(&phils->ru->finish);
	return (NULL);
}

static void	*routine(void *arg)
{
	t_philo	*phils;

	phils = (t_philo *)arg;
	if (phils->id % 2 == 0)
		ft_usleep(phils->ru->t_eat / 10);
	while (!ft_death(phils, 0))
	{
		pthread_create(&phils->death_id, NULL, ft_is_dead, arg);
		ft_eat(phils);
		pthread_detach(phils->death_id);
		if (++phils->nb_eat == phils->ru->cycle)
		{
			pthread_mutex_lock(&phils->ru->finish);
			phils->finish = 1;
			phils->ru->nb_phil_end++;
			if (phils->ru->nb_phil_end == phils->ru->nb_phil)
			{
				pthread_mutex_unlock(&phils->ru->finish);
				ft_death(phils, 2);
			}
			pthread_mutex_unlock(&phils->ru->finish);
			return (NULL);
		}
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
	return (0);
}
