/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:37:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/26 15:38:55 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include <pthread.h>

void	philo_eat(pthread_mutex_t *l_frk, pthread_mutex_t *r_frk, int tt_eat);
void	philo_sleep(int tt_sleep);
void	philo_think(int tt_think);

#endif
