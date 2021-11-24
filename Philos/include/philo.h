/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:57:04 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/23 12:37:41 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_rule
{
	unsigned int	nb_phil;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	int				cycle;
	pthread_mutex_t	write;
	pthread_mutex_t	death_mutex;
	int				death;
	unsigned int	start_time;
}	t_rule;

typedef struct s_philo
{
	pthread_t		th_id;
	pthread_t		death_check;
	int				id;
	pthread_mutex_t	r_f;
	pthread_mutex_t	*l_f;
	t_rule			*ru;
	int				nb_eat;
	unsigned int	last_eat;
}	t_philo;

typedef struct s_env
{
	t_philo		*phils;
	t_rule		rules;
}	t_env;

// Errors
int		ft_errorcheck(int argc, char **argv, t_env *env);
void	ft_init_rules(t_rule *rules);

// Utils
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
long	ft_atol(const char *s);
long	ft_isdigit(long c);
int		ft_loop_end(t_philo *phils);
void	ft_print_status(char *str, t_philo *phils);
unsigned int	ft_actual_time(void);
void	ft_usleep(unsigned int time_in_ms);
int		ft_death(t_philo *phils);

// Threads
int		ft_initthreads(t_env *env);
void	ft_init_phils(t_env *env);

#endif