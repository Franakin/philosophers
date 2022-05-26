/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 17:47:22 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/26 18:37:03 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include "timing_utils.h"

void	*start_thread(void *void_philo)
{
	t_philo			*philo;
	/*pthread_mutex_t	l_frk;
	pthread_mutex_t	r_frk;*/

	philo = (t_philo *)void_philo;
	/*if (philo->var->n_philos == 1)
		l_frk = NULL;
	else if (philo->i == 0)
		l_frk = philo->var->fork[philo->var->n_philos - 1];
	else
		l_frk = philo->var->fork[philo->i - 1];
	r_frk = philo->var->fork[philo->i];
	if (pthread_mutex_init(&r_frk, NULL))
		philo->var->exit = -4;
	routine(philo, &l_frk, &r_frk);*/
	pthread_mutex_lock(&philo->var->print_mutex);
	printf("Philosopher %d created at %llu\n", philo->i, get_timestamp(philo->var));
	pthread_mutex_unlock(&philo->var->print_mutex);
	return (NULL);
}
