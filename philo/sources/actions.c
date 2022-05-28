/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:29:40 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/28 18:47:32 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "h/timing_utils.h"
#include <stdio.h>

void	eat(t_philo *philo)
{
	unsigned long long	time_stamp;

	pthread_mutex_lock(philo->l_fork);
	time_stamp = get_timestamp(philo->var);
	pthread_mutex_lock(&philo->var->print_mutex);
	printf("%llu %d has taken a fork\n", time_stamp, philo->i);
	pthread_mutex_unlock(&philo->var->print_mutex);
	pthread_mutex_lock(philo->r_fork);
	time_stamp = get_timestamp(philo->var);
	pthread_mutex_lock(&philo->var->print_mutex);
	printf("%llu %d has taken a fork\n", time_stamp, philo->i);
	pthread_mutex_unlock(&philo->var->print_mutex);
	pthread_mutex_lock(&philo->var->print_mutex);
	printf("%llu %d is eating\n", time_stamp, philo->i);
	pthread_mutex_unlock(&philo->var->print_mutex);
	ft_delay((unsigned long long)(philo->var->tt_eat * 1000), philo->var);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleep(t_philo *philo)
{
	unsigned long long	time_stamp;

	time_stamp = get_timestamp(philo->var);
	pthread_mutex_lock(&philo->var->print_mutex);
	printf("%llu %d is sleeping\n", time_stamp, philo->i);
	pthread_mutex_unlock(&philo->var->print_mutex);
	ft_delay((unsigned long long)(philo->var->tt_sleep * 1000), philo->var);
}

void	think(t_philo *philo)
{
	unsigned long long	time_stamp;

	time_stamp = get_timestamp(philo->var);
	pthread_mutex_lock(&philo->var->print_mutex);
	printf("%llu %d is thinking\n", time_stamp, philo->i);
	pthread_mutex_unlock(&philo->var->print_mutex);
	ft_delay(10000, philo->var);
}
