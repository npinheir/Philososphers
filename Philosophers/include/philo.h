/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:57:04 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/19 11:34:58 by npinheir         ###   ########.fr       */
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
}	t_rule;

// Errors
int		ft_errorcheck(int argc, char **argv, t_rule *rules);
void	ft_init_rules(t_rule *rules);

// Utils
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *str);
long	ft_atol(const char *s);
long	ft_isdigit(long c);


#endif