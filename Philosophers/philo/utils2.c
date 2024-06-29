/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:39:20 by yathayde          #+#    #+#             */
/*   Updated: 2024/06/29 11:40:06 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*ft_wspaces(char *str)
{
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	return (str);
}

static int	ft_catnbr(char *str)
{
	unsigned int	c;
	unsigned int	mult;
	long int		result;

	c = 0;
	while (str[c] >= '0' && str[c] <= '9' && str[c] != 0)
		c++;
	mult = 1;
	result = 0;
	while (c > 0)
	{
		result += (str[c - 1] - '0') * mult;
		mult *= 10;
		c--;
	}
	return (result);
}

long int	ft_atoi(char *str)
{
	long int	result;

	result = 1;
	str = ft_wspaces(str);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			result = -1;
		str++;
	}
	result *= ft_catnbr(str);
	return (result);
}

void	ft_free(t_philo *philos)
{
	free(philos->dat->forks);
	free(philos->dat->print);
	free(philos->dat->loopm);
	free(philos->dat->meals);
	free(philos);
}

void	routine_philo(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(500);
	else
		usleep(1000);
	if (philo->dat->n_philos == 1)
	{
		ph_printf('f', philo);
		pthread_exit(NULL);
	}
}
