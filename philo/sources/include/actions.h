/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:37:29 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/06/07 19:37:03 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "philo.h"

int	p_eat(t_philo *philo);
int	p_sleep(t_philo *philo);
int	p_think(t_philo *philo);

#endif
