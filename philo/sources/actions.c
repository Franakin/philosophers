/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:29:40 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/07/20 14:44:48 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/timing_utils.h"
#include "include/print.h"
#include <stdio.h>

int	p_eat(t_philo *philo)
{
	if (pthread_mutex_lock(philo->l_fork))
		return (1);
	if (do_print("has taken a fork", philo->var, philo->n, &philo->start_time))
		return (1);
	if (pthread_mutex_lock(philo->r_fork))
		return (1);
	if (pthread_mutex_lock(&philo->var->meal_mutex[philo->n - 1]))
		return (1);
	philo->var->lst_meal[philo->n - 1] = get_timestamp(&philo->start_time);
	if (pthread_mutex_unlock(&philo->var->meal_mutex[philo->n - 1]))
		return (1);
	if (do_print("has taken a fork", philo->var, philo->n, &philo->start_time))
		return (1);
	if (do_print("is eating", philo->var, philo->n, &philo->start_time))
		return (1);
	ft_delay((unsigned long long)philo->var->tt_eat * 1000);
	if (pthread_mutex_unlock(philo->l_fork)
		|| pthread_mutex_unlock(philo->r_fork))
		return (1);
	return (0);
}

int	p_sleep(t_philo *philo)
{
	if (do_print("is sleeping", philo->var, philo->n, &philo->start_time))
		return (1);
	ft_delay((unsigned long long)philo->var->tt_sleep * 1000);
	return (0);
}

int	p_think(t_philo *philo)
{
	if (do_print("is thinking", philo->var, philo->n, &philo->start_time))
		return (1);
	return (0);
}
