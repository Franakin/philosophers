/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_var.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:23:49 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/06/07 19:47:59 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/timing_utils.h"
#include <limits.h>

static int	str_to_int(char *str)
{
	unsigned int	ret;
	int				i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (-3);
		ret = ret * 10 + (str[i] - 48);
		if (ret > INT_MAX)
			return (-3);
		i++;
	}
	return ((int)ret);
}

static int	parse_args(t_var *var, char **args)
{
	var->n_philos = str_to_int(args[1]);
	if (var->n_philos > 200)
		return (-2);
	else if (var->n_philos < 0)
		return (-3);
	var->tt_die = str_to_int(args[2]);
	if (var->tt_die < 0)
		return (-3);
	var->tt_eat = str_to_int(args[3]);
	if (var->tt_eat < 0)
		return (-3);
	var->tt_sleep = str_to_int(args[4]);
	if (var->tt_sleep < 0)
		return (-3);
	if (args[5] != NULL)
	{
		var->cycles = str_to_int(args[5]);
		if (var->cycles < 0)
			return (-3);
	}
	else
		var->cycles = -1;
	return (0);
}

int	create_var(t_var *var, char **args)
{
	var->exit = parse_args(var, args);
	if (var->exit)
		return (var->exit);
	var->start_time = 0;
	if (pthread_mutex_init(&var->print_mutex, NULL))
		return (-4);
	return (var->exit);
}
