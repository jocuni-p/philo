/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:00:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/16 15:55:49 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread(void *argv)
{
	t_philo	*philo;
	t_arg	*arg;

	philo = (t_philo *)argv;
	arg = philo->arg;
	pthread_mutex_lock(&arg->start_mtx);
	pthread_mutex_unlock(&arg->start_mtx);
	if ((philo->id % 2) != 0)
		usleep((arg->time_to_eat * 1000) - 500);
	while (!ft_get_finish(arg))
	{
		if (philo->meals_count < arg->target_meals)
			ft_philo_eating(arg, philo);
		if (philo->meals_count == arg->target_meals)
		{
			ft_set_philos_completed_meals(arg);
			return (0);
		}
		ft_philo_print(arg, philo->id, "is sleeping");
		ft_pass_time(arg->time_to_sleep, arg);
		ft_philo_print(arg, philo->id, "is thinking");
		if ((arg->num_of_philos % 2) != 0)
			ft_pass_time(arg->time_to_think, arg);
	}
	return (0);
}
