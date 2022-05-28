/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_threads.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 17:41:34 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/28 18:49:19 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "h/philo.h"

static int	init_forks(t_var *var)
{
	int	i;

	i = 1;
	while (i <= var->n_philos)
	{
		if (pthread_mutex_init(&var->fork[i], NULL))
			return (-4);
		i++;
	}
	return (0);
}

int	create_threads(t_var *var)
{
	int		i;
	t_philo	philo[201];

	if (init_forks(var))
		return (-4);
	i = 1;
	while (i <= var->n_philos)
	{
		philo[i].i = i;
		philo[i].var = var;
		if (pthread_create(&philo[i].philo, NULL, start_thread, &philo[i]))
			return (-4);
		i++;
	}
	i = 1;
	while (i <= var->n_philos)
	{
		if (pthread_join(philo[i].philo, NULL))
			return (-4);
		i++;
	}
	return (0);
}
