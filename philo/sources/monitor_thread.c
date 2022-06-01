/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor_thread.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 15:15:01 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/06/01 18:59:51 by fpurdom       ########   odam.nl         */
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
	while (!var->exit)
	{
		i = 1;
		var->t_stamp = get_timestamp(var);
		while (i <= var->n_philos)
		{
			if (var->lst_meal[i] + var->tt_die <= var->t_stamp)
			{
				var->exit = i;
				break ;
			}
			i++;
		}
		usleep(200);
	}
	if (var->exit > 0)
		printf("%llu %d has died\n", var->t_stamp, i);
	return (NULL);
}
