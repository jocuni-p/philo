/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:33:50 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/07 13:58:50 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Creates all threads, checks all the time if any of them has died and finaly
joins all of them.*/
int	ft_philo_start(t_arg *arg, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&arg->start_mtx);
	while (i < arg->num_of_philos)
	{
		philo[i].last_eat_time = ft_get_time();
		if (pthread_create(&philo[i].thread, 0, ft_thread, &philo[i]))
			return (ft_exit(ERR_THREAD, arg));
		i++;
	}
	arg->philo = philo;
	arg->simul_start_time = ft_get_time();
	pthread_mutex_unlock(&arg->start_mtx);
	ft_check_finish(arg, philo);
	i = 0;
	while (i < arg->num_of_philos)
	{
		if (pthread_join(philo[i].thread, NULL))
			return (ft_exit(ERR_THREAD, arg));
		i++;
	}
	return (0);
}
