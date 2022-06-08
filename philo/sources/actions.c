/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:29:40 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/06/08 16:05:24 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/timing_utils.h"
#include <stdio.h>

int	p_eat(t_philo *philo)
{
	if (pthread_mutex_lock(philo->l_fork))
		return (1);
	if (pthread_mutex_lock(&philo->var->print_mutex))
		return (1);
	if (!philo->var->exit)
		printf("%llu %d has taken a fork\n", philo->var->t_stamp, philo->n);
	if (pthread_mutex_unlock(&philo->var->print_mutex))
		return (1);
	if (pthread_mutex_lock(philo->r_fork))
		return (1);
	if (pthread_mutex_lock(&philo->var->print_mutex))
		return (1);
	if (!philo->var->exit)
	{
		printf("%llu %d has taken a fork\n", philo->var->t_stamp, philo->n);
		printf("%llu %d is eating\n", philo->var->t_stamp, philo->n);
	}
	if (pthread_mutex_unlock(&philo->var->print_mutex))
		return (1);
	philo->var->lst_meal[philo->n - 1] = philo->var->t_stamp;
	ft_delay((unsigned long long)philo->var->tt_eat * 1000);
	if (pthread_mutex_unlock(philo->l_fork)
		|| pthread_mutex_unlock(philo->r_fork))
		return (1);
	return (0);
}

int	p_sleep(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->var->print_mutex))
		return (1);
	if (!philo->var->exit)
		printf("%llu %d is sleeping\n", philo->var->t_stamp, philo->n);
	if (pthread_mutex_unlock(&philo->var->print_mutex))
		return (1);
	ft_delay((unsigned long long)philo->var->tt_sleep * 1000);
	return (0);
}

int	p_think(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->var->print_mutex))
		return (1);
	if (!philo->var->exit)
		printf("%llu %d is thinking\n", philo->var->t_stamp, philo->n);
	if (pthread_mutex_unlock(&philo->var->print_mutex))
		return (1);
	return (0);
}
