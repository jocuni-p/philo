/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:47:12 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/18 23:20:07 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Waits for a defined period of time*/
void	ft_pass_time(unsigned long wait_time, t_arg *arg)
{
	unsigned long	start;
	unsigned long	now;

	start = ft_get_time();
	while (ft_get_finish(arg) == 0)
	{
		now = ft_get_time();
		if ((now - start) >= wait_time)
			break ;
		usleep(100);
	}
}
