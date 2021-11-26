/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:53:21 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/25 10:25:38 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include "philo.h"

typedef struct s_rule
{
	int				cycle;
	int				death;
	unsigned int	nb_phil;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	start_time;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	write;
	
}	t_rule;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	unsigned int	last_eat;
	t_rule			*ru;
	pthread_t		th_id;
	pthread_t		death_check;
	pthread_mutex_t	r_f;
	pthread_mutex_t	*l_f;
}	t_philo;

typedef struct s_env
{
	t_rule			rules;
	t_philo			*phils;
}	t_env;

#endif