/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 13:54:46 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/16 15:43:38 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_eating(t_arg *arg, t_philo *philo)
{
	pthread_mutex_lock(&arg->forks[philo->first_fork]);
	ft_philo_print(arg, philo->id, "has taken a fork");
	if (philo->first_fork != philo->second_fork)
	{
		pthread_mutex_lock(&arg->forks[philo->second_fork]);
		ft_philo_print(arg, philo->id, "has taken a fork");
		ft_set_last_eat_time(philo);
		ft_philo_print(arg, philo->id, "is eating");
		ft_pass_time(arg->time_to_eat, arg);
		philo->meals_count++;
		pthread_mutex_unlock(&arg->forks[philo->second_fork]);
	}
	else
		ft_pass_time(arg->time_to_die, arg);
	pthread_mutex_unlock(&arg->forks[philo->first_fork]);
}
