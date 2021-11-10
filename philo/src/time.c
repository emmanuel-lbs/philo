/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:41:45 by elabasqu          #+#    #+#             */
/*   Updated: 2021/11/08 13:16:41 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long int	actual_time(void)
{
	long int	time;
	t_timeval	current_time;

	time = 0;
	if (gettimeofday(&current_time, NULL) == -1)
	{
		dprintf(1, "Gettimeofday returned -1\n");
		exit(0);
	}
	time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long int ms, t_philo *p)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < ms)
	{
		if (p->struc->data.nb_philos < 100)
			usleep(100);
		else
			usleep(1000);
	}
}
