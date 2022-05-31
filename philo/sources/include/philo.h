/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/21 15:14:14 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/31 19:41:23 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_var
{
	pthread_mutex_t		fork[201];
	pthread_mutex_t		print_mutex;
	unsigned long long	start_time;
	unsigned long long	t_stamp;
	int					n_philos;
	int					tt_die;
	int					tt_eat;
	int					tt_sleep;
	int					cycles;
	int					exit;
}				t_var;

typedef struct s_philo
{
	int				i;
	int				cycles;
	pthread_t		philo;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_var			*var;
}				t_philo;

int		create_var(t_var *var, char **args);
int		create_threads(t_var *var);
void	*routine(void *void_philo);
int		ft_exit(int code);

#endif