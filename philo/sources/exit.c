/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 16:35:45 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/09/01 16:34:30 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"
#include <stdio.h>

int	ft_exit(int code)
{
	if (code == -1)
		printf("Argument count error\n");
	else if (code == -2)
		printf("Philo number exceeds 200\n");
	else if (code == -3)
		printf("Error inside one or more arguments\n");
	else if (code == -4)
		printf("POSIX error init\n");
	else if (code == -5)
		printf("Error getting time of day\n");
	else
		return (0);
	return (code);
}

int	check_exit(pthread_mutex_t *mutex, int *exit)
{
	int	code;

	if (pthread_mutex_lock(mutex))
		return (1);
	if (*exit)
		code = 1;
	else
		code = 0;
	if (pthread_mutex_unlock(mutex))
		return (1);
	return (code);
}

int	set_exit(pthread_mutex_t *mutex, int *exit)
{
	if (pthread_mutex_lock(mutex))
		return (1);
	*exit = 1;
	if (pthread_mutex_unlock(mutex))
		return (1);
	return (0);
}
