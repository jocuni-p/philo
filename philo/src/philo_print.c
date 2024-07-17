/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:49:28 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/16 16:06:04 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_print(t_arg *arg, int id, char *str)
{
	unsigned long	now;

	pthread_mutex_lock(&(arg->print_mtx));
	now = ft_get_time();
	if (!ft_get_finish(arg))
		printf("%lu %d %s\n", now - arg->simul_start_time, id + 1, str);
	pthread_mutex_unlock(&(arg->print_mtx));
}
