/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timing_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:43:08 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/26 18:27:00 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philo.h"

void	ft_sleep(int delay, t_var *var)
{
	unsigned long long	start_time;
	unsigned long long	current_time;
	struct timeval		time;

	if (gettimeofday(&time, NULL))
		var->exit = -5;
	start_time = time.tv_sec * 1000000 + time.tv_usec;
	current_time = start_time;
	while (current_time < start_time + delay)
	{
		if (gettimeofday(&time, NULL))
			var->exit = -5;
		current_time = time.tv_sec * 1000000 + time.tv_usec;
	}
}

unsigned long long	get_start_time(t_var *var)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		var->exit = -5;
	return (time.tv_sec * 1000000 + time.tv_usec);
}

unsigned long long	get_timestamp(t_var *var)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		var->exit = -5;
	return ((time.tv_sec * 1000000 + time.tv_usec) - var->start_time);
}
