/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 14:04:21 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/28 18:59:06 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "h/actions.h"
#include "h/timing_utils.h"

void	routine(t_philo *philo)
{
	if (!(philo->i % 2))
		ft_delay(4000, philo->var);
	if (philo->var->cycles >= 0)
	{
		while (philo->var->cycles > 0 && philo->var->exit == 0)
		{
			eat(philo);
			sleep(philo);
			think(philo);
			philo->var->cycles--;
		}
	}
	else
	{
		while (philo->var->exit == 0)
		{
			eat(philo);
			sleep(philo);
			think(philo);
		}
	}
}
