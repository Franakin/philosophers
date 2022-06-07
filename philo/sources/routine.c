/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 14:04:21 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/06/07 20:19:32 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/actions.h"
#include "include/timing_utils.h"
#include <unistd.h>

static int	single_cycle(t_philo *philo)
{
	if (p_eat(philo))
		return (1);
	if (p_sleep(philo))
		return (1);
	if (p_think(philo))
		return (1);
	if (pthread_mutex_lock(&philo->var->print_mutex))
		return (1);
	if (philo->var->exit)
	{
		if (pthread_mutex_unlock(&philo->var->print_mutex))
			return (1);
		return (1);
	}
	if (pthread_mutex_unlock(&philo->var->print_mutex))
		return (1);
	return (0);
}

static int	cycled(t_philo *philo)
{
	while (philo->cycles > 0)
	{
		if (single_cycle(philo))
			return (1);
		philo->cycles--;
	}
	if (pthread_mutex_lock(&philo->var->print_mutex))
		return (1);
	philo->var->exit = 1;
	if (pthread_mutex_unlock(&philo->var->print_mutex))
		return (1);
	return (0);
}

static int	uncycled(t_philo *philo)
{
	while (1)
	{
		if (single_cycle(philo))
			return (1);
	}
}

void	*routine(void *void_philo)
{
	t_philo			*philo;

	philo = (t_philo *)void_philo;
	while (1)
	{
		pthread_mutex_lock(&philo->var->print_mutex);
		if (philo->var->start_time)
		{
			pthread_mutex_unlock(&philo->var->print_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->var->print_mutex);
		usleep(200);
	}
	if (!(philo->n % 2))
		ft_delay(2000);
	if (philo->cycles >= 0)
	{
		if (cycled(philo))
			;
	}
	else if (uncycled(philo))
		;
	return (NULL);
}
