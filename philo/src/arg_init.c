/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:53:32 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/15 14:11:36 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_arg_init_mutex(t_arg *arg)
{
	int	i;

	i = 0;
	arg->forks = malloc(sizeof(pthread_mutex_t) * arg->num_of_philos);
	if (!arg->forks)
		return (ft_exit(ERR_MALLOC, arg));
	while (i < arg->num_of_philos)
	{
		if (pthread_mutex_init(&arg->forks[i], NULL))
			return (ft_exit(ERR_MUTEX, arg));
		i++;
	}
	if (pthread_mutex_init(&arg->start_mtx, NULL))
		return (ft_exit(ERR_MUTEX, arg));
	if (pthread_mutex_init(&arg->print_mtx, NULL))
		return (ft_exit(ERR_MUTEX, arg));
	if (pthread_mutex_init(&arg->finish_mtx, NULL))
		return (ft_exit(ERR_MUTEX, arg));
	if (pthread_mutex_init(&arg->last_eat_time_mtx, NULL))
		return (ft_exit(ERR_MUTEX, arg));
	if (pthread_mutex_init(&arg->completed_meals_mtx, NULL))
		return (ft_exit(ERR_MUTEX, arg));
	return (0);
}

/*--Initializes all arg->variables and all elements of 'forks/mutex' array--*/
int	ft_arg_init(int argc, char *argv[], t_arg *arg)
{
	arg->num_of_philos = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	arg->target_meals = 2147483647;
	if (argc == 6)
		arg->target_meals = ft_atoi(argv[5]);
	arg->time_to_think = (arg->time_to_eat * 2) - arg->time_to_sleep;
	arg->simul_start_time = 0;
	arg->finish = 0;
	arg->philos_completed_meals = 0;
	if (ft_arg_init_mutex(arg))
		return (1);
	return (0);
}
