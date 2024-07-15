/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:48:49 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/13 16:32:00 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_arg	arg;
	t_philo	*philo;

	if (ft_arg_parsing(argc, argv))
		return (1);
	memset(&arg, 0, sizeof(t_arg));
	if (ft_arg_init(argc, argv, &arg))
		return (1);
	if (ft_philo_init(&arg, &philo))
		return (1);
	if (ft_philo_start(&arg, philo))
		return (1);
	ft_cleaner(&arg);
	return (0);
}
