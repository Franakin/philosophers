/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:15:14 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/05 18:22:36 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int argc, char **args)
{
	t_var	var;

	if (argc != 5 && argc != 6)
	{
		printf("Argument count error\n");
		return (1);
	}
	create_var(&var, args);
	create_threads(&var);
	if (var.error)
	{
		printf("An error occured\n");
		return (1);
	}
	return (0);
}
