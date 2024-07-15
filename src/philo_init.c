/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:39:26 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/13 14:13:26 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_init(t_arg *arg, t_philo **philo)
{
	int	i;

	i = 0;
	*philo = (t_philo *)malloc(sizeof(t_philo) * arg->num_of_philos);
	if (!*philo)
		return (ft_exit(ERR_MALLOC, arg));
	while (i < arg->num_of_philos)
	{
		(*philo)[i].arg = arg;
		(*philo)[i].id = i;
		if (i % 2 == 0)
		{
			(*philo)[i].first_fork = i;
			(*philo)[i].second_fork = (i + 1) % arg->num_of_philos;
		}
		else
		{
			(*philo)[i].first_fork = (i + 1) % arg->num_of_philos;
			(*philo)[i].second_fork = i;
		}
		(*philo)[i].meals_count = 0;
		(*philo)[i].last_eat_time = 0;
		i++;
	}
	return (0);
}
