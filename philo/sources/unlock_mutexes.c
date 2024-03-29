/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unlock_mutexes.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/08 13:59:37 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/08/31 15:28:19 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include <stdio.h>

void	*unlock_mutexes(t_var *var)
{
	int	i;

	if (pthread_mutex_unlock(&var->print_mutex))
		return (unlock_mutexes(var));
	if (pthread_mutex_lock(&var->print_mutex))
		return (unlock_mutexes(var));
	if (!var->exit)
	{
		var->exit = -4;
		printf("POSIX error thread\n");
	}
	if (pthread_mutex_unlock(&var->print_mutex))
		return (unlock_mutexes(var));
	i = 0;
	while (i < var->n_philos)
	{
		if (pthread_mutex_unlock(&var->fork[i]))
			return (unlock_mutexes(var));
		if (pthread_mutex_unlock(&var->meal_mutex[i]))
			return (unlock_mutexes(var));
		i++;
	}
	return (NULL);
}
