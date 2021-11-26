/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 08:02:19 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/25 10:25:32 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_death(t_philo *phils)
{
	pthread_mutex_lock(&phils->ru->death_mutex);
	if (phils->ru->death > 0)
	{
		pthread_mutex_lock(&phils->ru->write);
		printf("%d ", ft_actual_time() - phils->ru->start_time);
		printf("Philo %d died :(\n", phils->ru->death);
		pthread_mutex_unlock(&phils->ru->write);
		pthread_mutex_unlock(&phils->ru->death_mutex);
		exit(EXIT_SUCCESS);
		return (1);
	}
	pthread_mutex_unlock(&phils->ru->death_mutex);
	return (0);
}

int	ft_loop_end(t_philo *phils)
{
	if (phils->ru->cycle == -1)
		return (0);
	else
	{
		if (phils->nb_eat < phils->ru->cycle)
			return (0);
		else
			return (1);
	}
}

void	ft_sleep_think(t_philo *phils)
{
	pthread_mutex_lock(&phils->ru->write);
	ft_print_status("is sleeping ...\n", phils);
	pthread_mutex_unlock(&phils->ru->write);
	ft_usleep(phils->ru->t_sleep);

	pthread_mutex_lock(&phils->ru->write);
	ft_print_status("is thinking ...\n", phils);
	pthread_mutex_unlock(&phils->ru->write);
}

void	ft_eat(t_philo *phils)
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
	ft_print_status("is eating... ", phils);
	printf("%d times\n", phils->nb_eat + 1);
	pthread_mutex_unlock(&phils->ru->write);
	phils->last_eat = ft_actual_time();
	phils->nb_eat++;
	ft_usleep(phils->ru->t_eat);
	pthread_mutex_unlock(&phils->r_f);
	pthread_mutex_unlock(phils->l_f);
}