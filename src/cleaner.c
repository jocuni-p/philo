/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:31:59 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/13 17:09:01 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Clean all mutex and free allocated memory for a proper program finish*/
void	ft_cleaner(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->num_of_philos)
	{
		pthread_mutex_destroy(&arg->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&arg->start_mtx);
	pthread_mutex_destroy(&arg->print_mtx);
	pthread_mutex_destroy(&arg->finish_mtx);
	pthread_mutex_destroy(&arg->completed_meals_mtx);
	pthread_mutex_destroy(&arg->last_eat_time_mtx);
	if (arg->forks)
		free(arg->forks);
	if (arg->philo)
		free(arg->philo);
}
