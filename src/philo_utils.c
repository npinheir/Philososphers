/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 07:45:47 by npinheir          #+#    #+#             */
/*   Updated: 2021/12/06 06:53:22 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_loop(t_philo *phils)
{
	pthread_mutex_lock(&phils->ru->stop_mut);
	if (!phils->ru->stop && (phils->ru->cycle == -1
		|| phils->nb_eat < phils->ru->cycle))
	{
		pthread_mutex_unlock(&phils->ru->stop_mut);
		return (1);
	}
	pthread_mutex_unlock(&phils->ru->stop_mut);
	return (0);
}

void	ft_usleep(unsigned int time_in_ms)
{
	unsigned int	start_time;

	start_time = 0;
	start_time = ft_actual_time();
	while ((ft_actual_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}

void	ft_print_status(char *str, t_philo *phils)
{
	unsigned int	time;

	time = 0;
	time = ft_actual_time() - phils->ru->start_time;
	if (time <= 2147483647 && !ft_death(phils, 0))
	{
		printf("%d ", time);
		printf("Philo %d %s", phils->id, str);
	}
}

unsigned int	ft_actual_time(void)
{
	unsigned int	time;
	struct timeval	current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
		exit(EXIT_FAILURE);
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}
