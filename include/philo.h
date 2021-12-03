/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:52:32 by npinheir          #+#    #+#             */
/*   Updated: 2021/12/02 12:29:32 by npinheir         ###   ########.fr       */
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

# include "philo_struct.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

// Threads
int				ft_init_threads(t_env *env);
int				ft_death(t_philo *phils, int n);

// Activity
void			ft_eat(t_philo *phils);
void			ft_sleep_think(t_philo *phils);

// Philo utils
unsigned int	ft_actual_time(void);
void			ft_print_status(char *str, t_philo *phils);
void			ft_usleep(unsigned int time_in_ms);
int				ft_loop(t_philo *phils);

// Errors
int				ft_error_check(int argc, char **argv, t_env *env);

// Utils
int				ft_atoi(const char *str);
long			ft_atol(const char *str);

#endif