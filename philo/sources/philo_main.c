/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:15:14 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/09/20 17:33:22 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include "include/unlock_mutexes.h"

int	main(int argc, char **args)
{
	t_var	var;
	int		init_exit;

	if (argc != 5 && argc != 6)
		return (ft_exit(-1));
	init_exit = create_var(&var, args);
	if (init_exit)
		return (ft_exit(init_exit));
	if (var.cycles_cpy == 0 || var.n_philos == 0)
		return (0);
	init_exit = create_threads(&var);
	if (init_exit)
	{
		unlock_mutexes(&var);
		return (ft_exit(init_exit));
	}
	return (0);
}
