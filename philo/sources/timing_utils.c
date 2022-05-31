/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timing_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:43:08 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/31 19:52:27 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include <sys/time.h>
#include <unistd.h>

unsigned long long	get_start_time(t_var *var)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		var->exit = -5;
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	ft_delay(unsigned long long delay, t_var *var)
{
	unsigned long long	start_time;
	unsigned long long	current_time;

	start_time = get_start_time(var);
	current_time = start_time;
	while (current_time < start_time + delay)
	{
		current_time = get_start_time(var);
		usleep(200);
	}
}

unsigned long long	get_timestamp(t_var *var)
{
	unsigned long long	current_time;

	current_time = get_start_time(var);
	return ((current_time - var->start_time) / 1000);
}
