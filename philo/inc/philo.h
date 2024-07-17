/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 11:46:16 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/07/15 12:18:42 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>

# define ERR_LOWER_ARG "WARNING\nPARAMS MUST BE GREATER THAN 0\n"
# define ERR_ONLY_DIGITS "WARNING\nALL PARAMS MUST BE POSITIVE DIGITS\n"
# define ERR_ARGS "ERROR\nUSAGE: ./philo X XXX XX XX [OPTIONAL X]\n"
# define ERR_LIMITS "WARNING\nEXCEEDED PARAMETER LIMITS\n"
# define ERR_MALLOC "ABORT: MALLOC FAILED\n"
# define ERR_MUTEX "ABORT: ERROR MUTEX FAILURE\n"
# define ERR_THREAD "ABORT: ERROR CREATE OR JOIN A THREAD FAILURE\n"

# ifndef PHILO_LIMITATION
#  define PHILO_LIMITATION 250
# endif

typedef pthread_mutex_t	t_mtx;

typedef struct s_arg
{
	int				num_of_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	int				target_meals;//[optional_param]
	unsigned long	time_to_think;
	unsigned long	simul_start_time;
	t_mtx			*forks;
	t_mtx			start_mtx;
	t_mtx			print_mtx;
	t_mtx			finish_mtx;
	t_mtx			completed_meals_mtx;
	t_mtx			last_eat_time_mtx;
	int				finish;
	int				philos_completed_meals;
	struct s_philo	*philo;
}					t_arg;

typedef struct s_philo
{
	t_arg			*arg;
	pthread_t		thread;
	int				id;
	int				first_fork;
	int				second_fork;
	int				meals_count;
	unsigned long	last_eat_time;
}					t_philo;

int				ft_arg_parsing(int argc, char *argv[]);
int				ft_arg_init(int argc, char *argv[], t_arg *arg);
int				ft_philo_init(t_arg *arg, t_philo **philo);
int				ft_philo_start(t_arg *arg, t_philo *philo);
void			*ft_thread(void *argv);
void			ft_philo_eating(t_arg *arg, t_philo *philo);
void			ft_check_finish(t_arg *arg, t_philo *philo);
unsigned long	ft_get_time(void);
unsigned long	ft_get_last_eat_time(t_philo *philo);
void			ft_set_last_eat_time(t_philo *philo);
void			ft_pass_time(unsigned long wait_time, t_arg *arg);
int				ft_arg_limits(char *str, int i);
long long		ft_atoi(const char *str);
int				ft_isdigit(int c);
int				ft_get_finish(t_arg *arg);
void			ft_set_finish(t_arg *arg);
int				ft_get_philos_completed_meals(t_arg *arg);
void			ft_set_philos_completed_meals(t_arg *arg);
void			ft_philo_print(t_arg *arg, int id, char *str);
int				ft_exit(char *error_str, t_arg *arg);
void			ft_cleaner(t_arg *arg);

#endif
