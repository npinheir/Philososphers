/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:16:09 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/23 12:40:41 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_death(t_philo *phils)
{
	pthread_mutex_lock(&phils->ru->death_mutex);
	if (phils->ru->death > 0)
	{
		printf("philo %d died ...\n", phils->ru->death);
		pthread_mutex_unlock(&phils->ru->death_mutex);
		return(1);
	}
	pthread_mutex_unlock(&phils->ru->death_mutex);
	return (0);
}

int		ft_loop_end(t_philo *phils)
{
	if (phils->ru->cycle == -1)
		return (0);
	else
	{
		if (phils->nb_eat >= phils->ru->cycle)
			return (1);
		else
			return (0);
	}
}

void	ft_usleep(unsigned int time_in_ms)
{
	unsigned int	start_time;

	start_time = 0;
	start_time = ft_actual_time();
	while ((ft_actual_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
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

void	ft_print_status(char *str, t_philo *phils)
{
	unsigned int	time;

	time = 0;
	time = ft_actual_time() - phils->ru->start_time;
		printf("%d ", time);
		printf("Philo %dd %s", phils->id, str);
}