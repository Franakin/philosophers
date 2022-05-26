/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 14:04:21 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/26 18:11:24 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "actions.h"
#include "timing_utils.h"

void	routine(t_philo *philo, pthread_mutex_t *l_frk, pthread_mutex_t *r_frk)
{
	if (!(philo->i % 2))
		ft_delay(2000, philo->var);
	if (philo->cycles >= 0)
	{
		while (philo->cycles > 0)
		{
			philo_eat(l_frk, r_frk, philo->var->tt_eat);
			philo_sleep(philo->var->tt_sleep);
			philo_think(philo->var->tt_think);
		}
	}
	else
	{
		while (philo->var->error >= 0)
		{
			philo_eat(l_frk, r_frk, philo->var->tt_eat);
			philo_sleep(philo->var->tt_sleep);
			philo_think(philo->var->tt_think);
		}
	}
}
