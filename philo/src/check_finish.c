/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:31:08 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/18 23:25:06 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Check if the minimum meals have been reached or if any 'philo' has died*/
void	ft_check_finish(t_arg *arg, t_philo *philo)
{
	int				i;
	unsigned long	now;

	while (!ft_get_finish(arg))
	{
		if (arg->num_of_philos == ft_get_philos_completed_meals(arg))
		{
			ft_set_finish(arg);
			break ;
		}
		i = 0;
		while (i < arg->num_of_philos && !ft_get_finish(arg))
		{
			now = ft_get_time();
			if ((now - ft_get_last_eat_time(&philo[i])) >= arg->time_to_die)
			{
				ft_philo_print(arg, philo[i].id, "died");
				ft_set_finish(arg);
				break ;
			}
			i++;
		}
	}
}
