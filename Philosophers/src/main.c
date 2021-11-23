/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:56:55 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/22 09:28:00 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

static int	ft_letsplay(t_env *env)
{
	ft_init_phils(env);
	ft_initthreads(env);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;

	if (argc > 6 || argc < 5)
	{
		printf("\033[1;31m");
		printf("USAGE : ./philo <nb> <t_die> <t_eat> <t_sleep> [cycle]\n");
		return (1);
	}
	if (ft_errorcheck(argc, argv, &env))
	{
		printf("\033[1;31m");
		printf("Corrupted arguments ...");
		return (2);
	}
	env.phils = malloc(sizeof(t_philo) * env.rules.nb_phil);
	if (!env.phils)
		return (3);
	if (ft_letsplay(&env))
	{
		free(env.phils);
		return (4);
	}
	return (0);
}