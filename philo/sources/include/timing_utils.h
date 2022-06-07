/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timing_utils.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:49:50 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/06/07 19:06:11 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMING_UTILS_H
# define TIMING_UTILS_H

# include "philo.h"

void				ft_delay(int ms_delay);
unsigned long long	get_start_time(void);
unsigned long long	get_timestamp(unsigned long long *start_time);

#endif
