/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:37:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/31 19:56:27 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "philo.h"

void	do_all_actions(t_philo *philo);
void	eat(t_philo *philo);
void	sleep(t_philo *philo);
void	think(t_philo *philo);

#endif
