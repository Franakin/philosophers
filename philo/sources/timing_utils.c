/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timing_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:43:08 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/06/07 19:05:31 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include <sys/time.h>
#include <unistd.h>

unsigned long long	get_start_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (-1);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	ft_delay(unsigned long long delay)
{
	unsigned long long	start_time;
	unsigned long long	current_time;

	start_time = get_start_time();
	current_time = start_time;
	while (current_time < start_time + delay)
	{
		current_time = get_start_time();
		usleep(200);
	}
}

unsigned long long	get_timestamp(unsigned long long *start_time)
{
	unsigned long long	current_time;

	current_time = get_start_time();
	return ((current_time - *start_time) / 1000);
}
