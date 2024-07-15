/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:44:36 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/14 15:05:49 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Frees allocated memory and print an error message when abrupt exit occurs*/
int	ft_exit(char *error_str, t_arg *arg)
{
	if (arg->forks)
		free(arg->forks);
	if (arg->philo)
		free(arg->philo);
	if (error_str != NULL)
		printf("%s", error_str);
	return (1);
}
