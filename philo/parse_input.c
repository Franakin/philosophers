/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:23:49 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/05 15:07:04 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

static unsigned	int	str_to_int(char *str, t_var *var)
{
	unsigned int	ret;
	int				i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
		{
			var->error = 1;
			return (0);
		}
		ret = ret * 10 + (str[i] - 48);
		i++;
	}
	return (ret);
}

void	create_var(t_var *var, char **args)
{
	var->error = 0;
	var->n_philos = str_to_int(args[1], var);
	var->tt_die = str_to_int(args[2], var);
	var->tt_eat = str_to_int(args[3], var);
	var->tt_sleep = str_to_int(args[4], var);
	if (args[5] != NULL)
		var->cycles = str_to_int(args[5], var);
	else
		var->cycles = -1;
}
