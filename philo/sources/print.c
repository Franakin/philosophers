/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/20 14:05:39 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/07/21 16:18:40 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include "include/timing_utils.h"
#include <stdio.h>

int	print_any(const char *s, t_var *var, int n, unsigned long long *t)
{
	if (pthread_mutex_lock(&var->print_mutex))
		return (1);
	if (!var->exit)
		printf("%llu %d %s\n", get_timestamp(t), n, s);
	if (pthread_mutex_unlock(&var->print_mutex))
		return (1);
	return (0);
}

int	print_eating(t_var *var, int n, unsigned long long *t)
{
	unsigned long long	t_stamp;

	if (pthread_mutex_lock(&var->print_mutex))
		return (1);
	if (!var->exit)
	{
		t_stamp = get_timestamp(t);
		printf("%llu %d has taken a fork\n%llu %d is eating\n",
			t_stamp, n, t_stamp, n);
	}
	if (pthread_mutex_unlock(&var->print_mutex))
		return (1);
	return (0);
}
