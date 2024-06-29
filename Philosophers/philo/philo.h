/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:54:48 by yathayde          #+#    #+#             */
/*   Updated: 2024/06/04 09:41:03 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_dat
{
	int				n_philos;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	init_time;
	int				n_meals;
	int				max_meals;
	int				loop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*print;
	pthread_mutex_t	*loopm;
	pthread_mutex_t	*meals;
}	t_dat;

typedef struct s_philo
{
	unsigned long	l_eat;
	unsigned long	l_sleep;
	pthread_t		thid;
	int				id;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_dat			*dat;
}	t_philo;

int				check_entry(char **entry);
long int		ft_atoi(char *str);
void			init_params(t_dat *dat, char **argv);
t_philo			*init_philos(t_dat *dat);
void			*routine(void *arg);
unsigned long	time_us(void);
void			ft_usleep(unsigned long wait, t_dat *dat);
int				right_fork(t_philo philo);
int				check_loop(t_dat *dat);
void			ph_printf(char act, t_philo *philo);
void			ft_printf(char *str, unsigned long time, t_philo *philo);
void			kill(t_dat *dat);
void			update(t_dat *dat, unsigned long *var, unsigned long time);
int				check_meals(t_dat *dat);
void			update_meals(t_dat *dat);
void			ft_free(t_philo *philos);
void			routine_philo(t_philo *philo);

#endif
