/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:14:14 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/26 18:32:33 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_var
{
	int					n_philos;
	pthread_mutex_t		fork[201];
	pthread_mutex_t		print_mutex;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					cycles;
	int					exit;
	unsigned long long	start_time;
}				t_var;

typedef struct s_philo
{
	int				i;
	pthread_t		philo;
	t_var			*var;
}				t_philo;

int		create_var(t_var *var, char **args);
int		create_threads(t_var *var);
void	*start_thread(void *void_philo);
void	routine(t_philo *philo, pthread_mutex_t *l_frk, pthread_mutex_t *r_frk);
int		ft_exit(int code);

#endif
