/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/20 14:05:39 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/07/20 14:36:22 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include "include/timing_utils.h"
#include <stdio.h>

int	do_print(const char *s, t_var *var, int n, unsigned long long *t)
{
	if (pthread_mutex_lock(&var->print_mutex))
		return (1);
	if (!var->exit)
		printf("%llu %d %s\n", get_timestamp(t), n, s);
	if (pthread_mutex_unlock(&var->print_mutex))
		return (1);
	return (0);
}
