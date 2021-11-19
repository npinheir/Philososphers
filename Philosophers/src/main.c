/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:56:55 by npinheir          #+#    #+#             */
/*   Updated: 2021/11/19 10:54:10 by npinheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int		main(int argc, char **argv)
{
	t_rule	rules;

	if (argc > 6 || argc < 5)
	{
		printf("\033[1;31m");
		printf("USAGE : ./philo <nb> <t_die> <t_eat> <t_sleep> [cycle]\n");
		return (1);
	}
	bzero(&rules, sizeof(t_rule));
	if (ft_errorcheck(argc, argv, &rules))
	{
		printf("\033[1;31m");
		printf("Corrupted arguments ...");
		return (2);
	}
}