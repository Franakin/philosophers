/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_threads.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 17:41:34 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/06/08 13:53:19 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "include/timing_utils.h"

static int	init_forks(t_var *var, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < var->n_philos)
	{
		if (pthread_mutex_init(&var->fork[i], NULL))
			return (-4);
		if (var->n_philos == 1)
			philo[i].l_fork = &var->fork[i];
		else if (i == 0)
			philo[0].l_fork = &var->fork[var->n_philos - 1];
		else
			philo[i].l_fork = &var->fork[i - 1];
		philo[i].r_fork = &var->fork[i];
		i++;
	}
	return (0);
}

static void	init_philo_vars(t_philo *philo, t_var *var)
{
	int	i;

	i = 0;
	while (i < var->n_philos)
	{
		philo[i].n = i + 1;
		philo[i].cycles = var->cycles;
		philo[i].var = var;
		var->lst_meal[i] = 0;
		i++;
	}
}

static int	join_threads(t_philo *philo, t_var *var)
{
	int	i;

	i = 0;
	while (i < var->n_philos)
	{
		if (pthread_join(philo[i].philo, NULL))
			return (-4);
		i++;
	}
	if (pthread_join(var->monitor_thread, NULL))
		return (-4);
	return (0);
}

static int	init_threads(t_philo *philo, t_var *var)
{
	int	i;

	i = 0;
	while (i < var->n_philos)
	{
		if (pthread_create(&philo[i].philo, NULL, routine, &philo[i]))
			return (-4);
		i++;
	}
	if (pthread_create(&var->monitor_thread, NULL, monitor_thread, var))
		return (-4);
	return (0);
}

int	create_threads(t_var *var)
{
	t_philo	philo[200];

	if (init_forks(var, philo))
		return (-4);
	init_philo_vars(philo, var);
	if (init_threads(philo, var))
		return (-4);
	if (pthread_mutex_lock(&var->print_mutex))
		return (-4);
	var->start_time = get_start_time();
	if (pthread_mutex_unlock(&var->print_mutex))
		return (-4);
	if (join_threads(philo, var))
		return (-4);
	return (0);
}
