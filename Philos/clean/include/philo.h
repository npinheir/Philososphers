/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:52:32 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/23 13:13:47 by npinheir         ###   ########.fr       */
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

// Errors
int		ft_error_check(int argc, char **argv, t_env *env);

// Utils
int		ft_atoi(const char *str);

long	ft_atol(const char *str);

#endif