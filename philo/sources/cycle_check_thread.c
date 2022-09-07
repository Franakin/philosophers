/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cycle_check_thread.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 15:53:09 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/09/02 15:44:08 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include "include/unlock_mutexes.h"
#include <unistd.h>

static int	check_loop(t_var *var)
{
	int	i;

	i = 0;
	while (i < var->n_philos)
	{
		if (pthread_mutex_lock(&var->cycle_mutex[i]))
			return (-4);
		if (var->cycles[i] > 1)
		{
			if (pthread_mutex_unlock(&var->cycle_mutex[i]))
				return (-4);
			return (0);
		}
		if (pthread_mutex_unlock(&var->cycle_mutex[i]))
			return (-4);
		i++;
	}
	return (1);
}

void	*cycle_check(void *void_var)
{
	t_var	*var;
	int		status;

	var = (t_var *)void_var;
	while (1)
	{
		if (check_exit(&var->print_mutex, &var->exit))
			return (NULL);
		status = check_loop(var);
		if (status > 0)
		{
			set_exit(&var->print_mutex, &var->exit);
			return (NULL);
		}
		else if (status < 0)
			return (unlock_mutexes(var));
		usleep(200);
	}
	return (NULL);
}
