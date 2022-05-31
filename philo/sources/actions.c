/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:29:40 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/31 19:55:30 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/timing_utils.h"
#include <stdio.h>

void	do_all_actions(t_philo *philo)
{
	eat(philo);
	sleep(philo);
	think(philo);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	philo->var->t_stamp = get_timestamp(philo->var);
	pthread_mutex_lock(&philo->var->print_mutex);
	printf("%llu %d has taken a fork\n", philo->var->t_stamp, philo->i);
	pthread_mutex_unlock(&philo->var->print_mutex);
	pthread_mutex_lock(philo->r_fork);
	philo->var->t_stamp = get_timestamp(philo->var);
	pthread_mutex_lock(&philo->var->print_mutex);
	printf("%llu %d has taken a fork\n", philo->var->t_stamp, philo->i);
	printf("%llu %d is eating\n", philo->var->t_stamp, philo->i);
	pthread_mutex_unlock(&philo->var->print_mutex);
	ft_delay((unsigned long long)(philo->var->tt_eat) * 1000, philo->var);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleep(t_philo *philo)
{
	philo->var->t_stamp = get_timestamp(philo->var);
	pthread_mutex_lock(&philo->var->print_mutex);
	printf("%llu %d is sleeping\n", philo->var->t_stamp, philo->i);
	pthread_mutex_unlock(&philo->var->print_mutex);
	ft_delay((unsigned long long)(philo->var->tt_sleep) * 1000, philo->var);
}

void	think(t_philo *philo)
{
	philo->var->t_stamp = get_timestamp(philo->var);
	pthread_mutex_lock(&philo->var->print_mutex);
	printf("%llu %d is thinking\n", philo->var->t_stamp, philo->i);
	pthread_mutex_unlock(&philo->var->print_mutex);
}
