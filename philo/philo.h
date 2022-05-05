/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:14:14 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/05 19:22:13 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_var
{
	unsigned int	n_philos;
	unsigned int	tt_die;
	unsigned int	tt_eat;
	unsigned int	tt_sleep;
	unsigned int	cycles;
	int				error;
}				t_var;

typedef struct s_philo
{
	unsigned int	i;
	pthread_t		philo;
	t_var			*var;
}				t_philo;

void	create_var(t_var *var, char **args);
void	create_threads(t_var *var);
void	*routine(void *void_philo);

#endif
