/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 17:41:34 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/05 19:27:37 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <stdio.h>

void	create_threads(t_var *var)
{
	int			i;
	t_philo		philos[200];

	i = 0;
	while (i < var->n_philos)
	{
		philos[i].i = i;
		philos[i].var = var;
		if (pthread_create(&philos[i].philo, NULL, routine, &philos[i]))
		{
			var->error = 1;
			return ;
		}
		i++;
	}
	i = 0;
	while (i < var->n_philos)
	{
		pthread_join(philos[i].philo, NULL);
		i++;
	}
}
