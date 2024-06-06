/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:46:38 by yathayde          #+#    #+#             */
/*   Updated: 2024/06/04 09:39:19 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	think(t_philo *philo)
{
	ph_printf('t', philo);
	usleep(200);
}

static void	sleepth(t_philo *philo)
{
	ph_printf('s', philo);
	ft_usleep(philo->dat->time_to_sleep - (time_us()
			- philo->l_sleep), philo->dat);
}

static void	forks(t_philo *philo, pthread_mutex_t *r_f, pthread_mutex_t *l_f)
{
	pthread_mutex_lock(r_f);
	ph_printf('f', philo);
	pthread_mutex_lock(l_f);
	ph_printf('f', philo);
	ph_printf('e', philo);
	ft_usleep(philo->dat->time_to_eat - (time_us() - philo->l_eat), philo->dat);
	pthread_mutex_unlock(r_f);
	pthread_mutex_unlock(l_f);
}

static void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		forks(philo, philo->r_fork, philo->l_fork);
	else
		forks(philo, philo->l_fork, philo->r_fork);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	int			meals;

	meals = 0;
	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);
	if (philo->dat->n_philos == 1)
	{
		ph_printf('f', philo);
		return (NULL);
	}
	while (!check_loop(philo->dat))
	{
		eat(philo);
		meals++;
		//printf("philo %d; meal: %d & max_meals:  %d\n", philo->id, meals, philo->dat->max_meals);
		if (meals == philo->dat->max_meals)
		{
			update_meals(philo->dat);
			return(NULL);
		}
		sleepth(philo);
		think(philo);
	}
	return (NULL);
}
