/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:13:42 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/15 12:18:15 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	int				i;
	unsigned long	nbr;
	int				flag;

	i = 0;
	nbr = 0;
	flag = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		flag++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	if (flag == 1)
		nbr = -nbr;
	return (nbr);
}

int	ft_arg_limits(char *str, int i)
{
	long long	nbr;

	nbr = ft_atoi(str);
	if (i == 1 && (nbr <= 0 || nbr > PHILO_LIMITATION))
		return (1);
	if (i >= 2 && i <= 4)
	{
		if (nbr <= 0 || nbr > INT_MAX)
			return (1);
	}
	if (i == 5 && (nbr > INT_MAX || nbr < 0))
		return (1);
	return (0);
}

/*Checks for nbr of args, positive digits and int limits*/
int	ft_arg_parsing(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	if (argc < 5 || argc > 6)
		return ((printf(ERR_ARGS) * 0) + 1);
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf(ERR_ONLY_DIGITS);
				return (1);
			}
			j++;
		}
		if (ft_atoi(argv[i]) <= 0)
			return ((printf(ERR_LOWER_ARG) * 0) + 1);
		if (ft_arg_limits(argv[i], i))
			return ((printf(ERR_LIMITS) * 0) + 1);
	}
	return (0);
}
