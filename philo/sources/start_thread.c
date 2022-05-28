/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_thread.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 17:47:22 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/28 18:47:58 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "h/philo.h"

void	*start_thread(void *void_philo)
{
	t_philo			*philo;

	philo = (t_philo *)void_philo;
	if (philo->var->n_philos == 1)
		philo->l_fork = &philo->var->fork[philo->i];
	else if (philo->i == 1)
		philo->l_fork = &philo->var->fork[philo->var->n_philos];
	else
		philo->l_fork = &philo->var->fork[philo->i - 1];
	philo->r_fork = &philo->var->fork[philo->i];
	routine(philo);
	return (NULL);
}
