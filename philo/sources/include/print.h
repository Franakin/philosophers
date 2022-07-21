/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fpurdom <fpurdom@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/20 14:15:14 by fpurdom       #+#    #+#                 */
/*   Updated: 2022/07/21 16:14:25 by fpurdom       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include "philo.h"

int	print_any(const char *s, t_var *var, int n, unsigned long long *t);
int	print_eating(t_var *var, int n, unsigned long long *t);

#endif
