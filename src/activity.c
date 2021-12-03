/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 08:02:19 by npinheir          #+#    #+#             */
/*   Updated: 2021/12/02 12:35:14 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (!phils->l_f)
	{
		ft_usleep(phils->ru->t_die * 2);
		return ;
	}
	pthread_mutex_lock(phils->l_f);
	pthread_mutex_lock(&phils->ru->write);
	ft_print_status("has taken a fork.\n", phils);
	pthread_mutex_unlock(&phils->ru->write);
	pthread_mutex_lock(&phils->ru->write);
	ft_print_status("is eating ...\n", phils);
	pthread_mutex_lock(&phils->ru->time_check);
	phils->last_eat = ft_actual_time();
	pthread_mutex_unlock(&phils->ru->time_check);
	pthread_mutex_unlock(&phils->ru->write);
	ft_usleep(phils->ru->t_eat);
	pthread_mutex_unlock(&phils->r_f);
	pthread_mutex_unlock(phils->l_f);
	ft_sleep_think(phils);
}
