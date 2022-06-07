/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor_thread.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 15:15:01 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/06/07 20:03:37 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/timing_utils.h"
#include <unistd.h>
#include <stdio.h>

void	*monitor_thread(void *void_var)
{
	t_var				*var;
	int					i;

	var = (t_var *)void_var;
	while (1)
	{
		i = 0;
		pthread_mutex_lock(&var->print_mutex);
		var->t_stamp = get_timestamp(&var->start_time);
		while (i < var->n_philos && !var->exit)
		{
			if (var->lst_meal[i] + var->tt_die < var->t_stamp)
			{
				var->exit = i + 1;
				printf("%llu %d has died\n", var->t_stamp, i + 1);
				break ;
			}
			i++;
		}
		if (var->exit)
		{
			pthread_mutex_unlock(&var->print_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&var->print_mutex);
		usleep(200);
	}
	return (NULL);
}
