/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timing_utils.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:49:50 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/28 16:33:35 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMING_UTILS_H
# define TIMING_UTILS_H

# include "philo.h"

void				ft_delay(int ms_delay, t_var *var);
unsigned long long	get_start_time(t_var *var);
unsigned long long	get_timestamp(t_var *var);

#endif
