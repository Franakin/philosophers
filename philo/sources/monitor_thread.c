/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor_thread.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 15:15:01 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/06/20 17:46:15 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/timing_utils.h"
#include "include/unlock_mutexes.h"
#include <unistd.h>
#include <stdio.h>

static int	death_loop(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->n_philos)
	{
		if (pthread_mutex_lock(&var->print_mutex))
			return (1);
		if (var->lst_meal[i] + var->tt_die < var->t_stamp)
		{
			if (pthread_mutex_unlock(&var->print_mutex))
				return (1);
			if (pthread_mutex_lock(&var->exit_mutex))
				return (1);
			var->exit = i + 1;
			if (pthread_mutex_unlock(&var->exit_mutex))
				return (1);
			if (pthread_mutex_lock(&var->print_mutex))
				return (1);
			printf("%llu %d has died\n", var->t_stamp, i + 1);
			if (pthread_mutex_unlock(&var->print_mutex))
				return (1);
			return (0);
		}
		if (pthread_mutex_unlock(&var->print_mutex))
			return (1);
		i++;
	}
	return (0);
}

void	*monitor_thread(void *void_var)
{
	t_var	*var;

	var = (t_var *)void_var;
	while (1)
	{
		if (pthread_mutex_lock(&var->print_mutex))
			return (unlock_mutexes(var));
		var->t_stamp = get_timestamp(&var->start_time);
		if (pthread_mutex_unlock(&var->print_mutex))
			return (unlock_mutexes(var));
		if (death_loop(var))
			return (unlock_mutexes(var));
		if (pthread_mutex_lock(&var->exit_mutex))
			return (unlock_mutexes(var));
		if (var->exit)
		{
			if (pthread_mutex_unlock(&var->exit_mutex))
				return (unlock_mutexes(var));
			return (NULL);
		}
		if (pthread_mutex_unlock(&var->exit_mutex))
			return (unlock_mutexes(var));
		usleep(200);
	}
	return (NULL);
}
