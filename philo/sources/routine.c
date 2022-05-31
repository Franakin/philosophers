/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 14:04:21 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/31 19:56:00 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/actions.h"
#include "include/timing_utils.h"

void	*routine(void *void_philo)
{
	t_philo			*philo;

	philo = (t_philo *)void_philo;
	while (!philo->var->start_time)
		;
	if (!(philo->i % 2))
		ft_delay(2000, philo->var);
	if (philo->cycles >= 0)
	{
		while (philo->cycles > 0 && philo->var->exit == 0)
		{
			do_all_actions(philo);
			philo->cycles--;
		}
	}
	else
	{
		while (philo->var->exit == 0)
			do_all_actions(philo);
	}
	return (NULL);
}
