/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:24:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/18 23:22:36 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Sets the value of a variable which is protected by mutexes*/
void	ft_set_finish(t_arg *arg)
{
	pthread_mutex_lock(&arg->finish_mtx);
	arg->finish = 1;
	pthread_mutex_unlock(&arg->finish_mtx);
}

void	ft_set_philos_completed_meals(t_arg *arg)
{
	pthread_mutex_lock(&arg->completed_meals_mtx);
	arg->philos_completed_meals += 1;
	pthread_mutex_unlock(&arg->completed_meals_mtx);
}

void	ft_set_last_eat_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->arg->last_eat_time_mtx);
	philo->last_eat_time = ft_get_time();
	pthread_mutex_unlock(&philo->arg->last_eat_time_mtx);
}
