/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:24:29 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/13 14:19:55 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_finish(t_arg *arg)
{
	int	finish;

	pthread_mutex_lock(&arg->finish_mtx);
	finish = arg->finish;
	pthread_mutex_unlock(&arg->finish_mtx);
	return (finish);
}

int	ft_get_philos_completed_meals(t_arg *arg)
{
	int	completed;

	pthread_mutex_lock(&arg->completed_meals_mtx);
	completed = arg->philos_completed_meals;
	pthread_mutex_unlock(&arg->completed_meals_mtx);
	return (completed);
}

unsigned long	ft_get_last_eat_time(t_philo *philo)
{
	unsigned long	last_eat_time;

	pthread_mutex_lock(&philo->arg->last_eat_time_mtx);
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->arg->last_eat_time_mtx);
	return (last_eat_time);
}
