/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:34:54 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/13 13:21:39 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Returns the current time in miliseconds*/
unsigned long	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("Error. 'gettimeofday' failed.\n");
		return (1);
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
