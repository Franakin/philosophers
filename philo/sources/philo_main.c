/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:15:14 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/26 18:08:02 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int argc, char **args)
{
	t_var	var;

	if (argc != 5 && argc != 6)
	{
		var.exit = -1;
		return (ft_exit(var.exit));
	}
	var.exit = create_var(&var, args);
	if (var.exit)
		return (ft_exit(var.exit));
	var.exit = create_threads(&var);
	if (var.exit)
		return (ft_exit(var.exit));
	return (0);
}
