/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 14:04:21 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/09/02 16:40:09 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/actions.h"
#include "include/timing_utils.h"
#include "include/unlock_mutexes.h"
#include <unistd.h>

static int	single_cycle(t_philo *philo)
{
	if (p_eat(philo))
		return (1);
	if (p_sleep(philo))
		return (1);
	if (p_think(philo))
		return (1);
	return (0);
}

static int	cycled(t_philo *philo)
{
	while (1)
	{
		if (check_exit(&philo->var->print_mutex, &philo->var->exit))
			return (0);
		if (single_cycle(philo))
			return (1);
		if (pthread_mutex_lock(&philo->var->cycle_mutex[philo->n - 1]))
			return (1);
		philo->var->cycles[philo->n - 1]--;
		if (pthread_mutex_unlock(&philo->var->cycle_mutex[philo->n - 1]))
			return (1);
	}
	return (0);
}

static int	uncycled(t_philo *philo)
{
	while (1)
	{
		if (check_exit(&philo->var->print_mutex, &philo->var->exit))
			return (0);
		if (single_cycle(philo))
			return (1);
	}
}

static int	wait_for_threads(t_philo *philo)
{
	while (1)
	{
		if (pthread_mutex_lock(&philo->var->print_mutex))
			return (1);
		if (philo->var->start_time)
		{
			philo->start_time = philo->var->start_time;
			if (pthread_mutex_unlock(&philo->var->print_mutex))
				return (1);
			return (0);
		}
		if (pthread_mutex_unlock(&philo->var->print_mutex))
			return (1);
		if (check_exit(&philo->var->print_mutex, &philo->var->exit))
			return (0);
		usleep(200);
	}
}

void	*routine(void *void_philo)
{
	t_philo			*philo;

	philo = (t_philo *)void_philo;
	if (wait_for_threads(philo))
		return (unlock_mutexes(philo->var));
	if (!(philo->n % 2))
		ft_delay(2000);
	if (philo->var->cycles_cpy >= 0)
	{
		if (cycled(philo))
			return (unlock_mutexes(philo->var));
	}
	else if (uncycled(philo))
		return (unlock_mutexes(philo->var));
	return (NULL);
}
