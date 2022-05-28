/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:15:14 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/28 18:47:48 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "h/philo.h"

int	main(int argc, char **args)
{
	t_var	var;

	if (argc != 5 && argc != 6)
		return (ft_exit(-1));
	var.exit = create_var(&var, args);
	if (var.exit)
		return (ft_exit(var.exit));
	var.exit = create_threads(&var);
	if (var.exit)
		return (ft_exit(var.exit));
	return (0);
}
