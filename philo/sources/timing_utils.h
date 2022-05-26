/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timing_utils.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/26 15:49:50 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/05/26 18:12:31 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMING_UTILS_H
# define TIMING_UTILS_H

void				ft_delay(int delay);
unsigned long long	get_start_time(t_var *var);
unsigned long long	get_timestamp(t_var *var);

#endif
