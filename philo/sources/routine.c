/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 14:04:21 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/06/02 16:06:00 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/actions.h"
#include "include/timing_utils.h"
#include <unistd.h>

static void	cycled(t_philo *philo)
{
	while (philo->cycles > 0 && philo->var->exit == 0)
	{
		if (!philo->var->exit)
			p_eat(philo);
		if (!philo->var->exit)
			p_sleep(philo);
		if (!philo->var->exit)
			p_think(philo);
		philo->cycles--;
	}
}

static void	uncycled(t_philo *philo)
{
	while (philo->var->exit == 0)
	{
		if (!philo->var->exit)
			p_eat(philo);
		if (!philo->var->exit)
			p_sleep(philo);
		if (!philo->var->exit)
			p_think(philo);
	}
}

void	*routine(void *void_philo)
{
	t_philo			*philo;

	philo = (t_philo *)void_philo;
	while (!philo->var->start_time)
		usleep(200);
	if (!(philo->i % 2))
		ft_delay(2000, philo->var);
	if (philo->cycles >= 0)
		cycled(philo);
	else
		uncycled(philo);
	return (NULL);
}
