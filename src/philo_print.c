/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:49:28 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/15 16:17:06 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_print(t_arg *arg, int id, char *str)
{
	unsigned long	now;

	pthread_mutex_lock(&(arg->print_mtx));
	now = ft_get_time();
//	if (!ft_get_finish(arg))//OJO potser el finish no hauria de tenir mutex
	if (arg->finish == 0)
	{
		printf("%lu %d %s\n", now - arg->simul_start_time, id + 1, str);
	}
	pthread_mutex_unlock(&(arg->print_mtx));
}
