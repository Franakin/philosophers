/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_threads.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 17:41:34 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/26 18:41:46 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	create_threads(t_var *var)
{
	int		i;
	t_philo	philos[201];

	i = 1;
	while (i <= var->n_philos)
	{
		philos[i].i = i;
		philos[i].var = var;
		if (pthread_create(&philos[i].philo, NULL, start_thread, &philos[i]))
			return (-4);
		i++;
	}
	i = 1;
	while (i <= var->n_philos)
	{
		if (pthread_join(philos[i].philo, NULL))
			return (-4);
		i++;
	}
	return (0);
}
