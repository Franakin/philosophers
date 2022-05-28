/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 16:35:45 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/26 17:24:24 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
		printf("POSIX thread error\n");
	else if (code == -5)
		printf("Error getting time of day\n");
	else if (code > 0)
	{
		printf("Philosopher %d has died\n", code);
		return (0);
	}
	return (code);
}