/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:29:40 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/06/02 18:29:05 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/timing_utils.h"
#include <stdio.h>

void	p_eat(t_philo *philo)
{
	if (pthread_mutex_lock(philo->l_fork))
		philo->var->exit = -4;
	if (pthread_mutex_lock(&philo->var->print_mutex))
		philo->var->exit = -4;
	if (!philo->var->exit)
		printf("%llu %d has taken a fork\n", philo->var->t_stamp, philo->i);
	if (pthread_mutex_unlock(&philo->var->print_mutex))
		philo->var->exit = -4;
	if (pthread_mutex_lock(philo->r_fork))
		philo->var->exit = -4;
	if (pthread_mutex_lock(&philo->var->print_mutex))
		philo->var->exit = -4;
	if (!philo->var->exit)
	{
		printf("%llu %d has taken a fork\n", philo->var->t_stamp, philo->i);
		printf("%llu %d is eating\n", philo->var->t_stamp, philo->i);
	}
	if (pthread_mutex_unlock(&philo->var->print_mutex))
		philo->var->exit = -4;
	ft_delay((unsigned long long)philo->var->tt_eat * 1000, philo->var);
	philo->var->lst_meal[philo->i] = philo->var->t_stamp;
	if (pthread_mutex_unlock(philo->l_fork))
		philo->var->exit = -4;
	if (pthread_mutex_unlock(philo->r_fork))
		philo->var->exit = -4;
}

void	p_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->var->print_mutex);
	if (!philo->var->exit)
		printf("%llu %d is sleeping\n", philo->var->t_stamp, philo->i);
	pthread_mutex_unlock(&philo->var->print_mutex);
	ft_delay((unsigned long long)philo->var->tt_sleep * 1000, philo->var);
}

void	p_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->var->print_mutex);
	if (!philo->var->exit)
		printf("%llu %d is thinking\n", philo->var->t_stamp, philo->i);
	pthread_mutex_unlock(&philo->var->print_mutex);
}
