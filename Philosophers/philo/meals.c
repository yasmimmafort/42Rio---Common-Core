/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:39:05 by yathayde          #+#    #+#             */
/*   Updated: 2024/06/04 09:39:08 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_dat *dat)
{
	int	ret;

	pthread_mutex_lock(dat->meals);
	ret = dat->n_meals;
	pthread_mutex_unlock(dat->meals);
	return (ret);
}

void	update_meals(t_dat *dat)
{
	pthread_mutex_lock(dat->meals);
	dat->n_meals++;
	pthread_mutex_unlock(dat->meals);
}

void	ft_printf(char *str, unsigned long time, t_philo *philo)
{
	if (check_loop(philo->dat))
		return ;
	pthread_mutex_lock(philo->dat->print);
	if (check_loop(philo->dat))
	{
		pthread_mutex_unlock(philo->dat->print);
		return ;
	}
	printf("%05ld %i %s",
		(time - philo->dat->init_time) / 1000, philo->id, str);
	pthread_mutex_unlock(philo->dat->print);
}

void	update(t_dat *dat, unsigned long *var, unsigned long time)
{
	pthread_mutex_lock(dat->loopm);
	*var = time;
	pthread_mutex_unlock(dat->loopm);
}

void	ph_printf(char act, t_philo *philo)
{
	unsigned long	now;

	now = time_us();
	if (act == 'e')
	{
		update(philo->dat, &(philo->l_eat), now);
		ft_printf("is eating\n", now, philo);
	}
	else if (act == 't')
		ft_printf("is thinking\n", now, philo);
	else if (act == 'f')
		ft_printf("has taken a fork\n", now, philo);
	else if (act == 's')
	{
		update(philo->dat, &(philo->l_sleep), now);
		ft_printf("is sleeping\n", now, philo);
	}
}
