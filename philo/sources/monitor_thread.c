/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor_thread.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 15:15:01 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/09/20 18:59:09 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/timing_utils.h"
#include "include/unlock_mutexes.h"
#include "include/print.h"
#include <unistd.h>

static int	cycle_check(t_var *var)
{
	if (pthread_mutex_lock(&var->cycle_mutex))
		return (1);
	if (var->cycles_check == 0)
	{
		if (pthread_mutex_unlock(&var->cycle_mutex))
			return (1);
		set_exit(&var->print_mutex, &var->exit);
		return (1);
	}
	if (pthread_mutex_unlock(&var->cycle_mutex))
		return (1);
	return (0);
}

static int	death_loop(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->n_philos)
	{
		if (pthread_mutex_lock(&var->meal_mutex[i]))
			return (1);
		if (var->lst_meal[i] + var->tt_die < var->t_stamp)
		{
			if (pthread_mutex_unlock(&var->meal_mutex[i]))
				return (1);
			if (print_any("has died", var, i + 1, &var->start_time))
				return (1);
			set_exit(&var->print_mutex, &var->exit);
			return (1);
		}
		else if (pthread_mutex_unlock(&var->meal_mutex[i]))
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
		if (check_exit(&var->print_mutex, &var->exit))
			return (NULL);
		var->t_stamp = get_timestamp(&var->start_time);
		if (death_loop(var))
			return (unlock_mutexes(var));
		if (var->cycles_cpy)
		{
			if (cycle_check(var))
				return (unlock_mutexes(var));
		}
		usleep(200);
	}
}
