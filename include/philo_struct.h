/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:53:21 by npinheir          #+#    #+#             */
/*   Updated: 2021/12/02 11:37:07 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include "philo.h"

typedef struct s_rule
{
	int				stop;
	int				cycle;
	unsigned int	nb_phil;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	start_time;
	unsigned int	nb_phil_end;
	pthread_mutex_t	time_check;
	pthread_mutex_t	stop_mut;
	pthread_mutex_t	finish;
	pthread_mutex_t	write;
}	t_rule;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	int				finish;
	unsigned int	last_eat;
	t_rule			*ru;
	pthread_t		th_id;
	pthread_t		death_id;
	pthread_mutex_t	r_f;
	pthread_mutex_t	*l_f;
}	t_philo;

typedef struct s_env
{
	t_rule			rules;
	t_philo			*phils;
}	t_env;

#endif