/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:27:42 by elabasqu          #+#    #+#             */
/*   Updated: 2021/11/09 09:02:35 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	printf_philo(t_philo *p, char *action)
{
	gettimeofday(&p->struc->t_now, NULL);
	pthread_mutex_lock(&p->struc->m_write);
	if (p->struc->death == 1)
	{
		printf("%ld ", actual_time() - p->struc->t_init);
		printf("%d ", p->n + 1);
		printf("%s\n", action);
	}
	pthread_mutex_unlock(&p->struc->m_write);
}

static void	do_something(t_philo *p)
{
	pthread_mutex_lock(p->l_fork);
	printf_philo(p, "has taken a fork");
	if (p->struc->data.nb_philos == 1)
	{
		ft_usleep(p->struc->data.t_die, p);
		pthread_mutex_unlock(p->l_fork);
		return ;
	}
	pthread_mutex_lock(&p->r_fork);
	printf_philo(p, "has taken a fork");
	printf_philo(p, "is eating");
	p->nb_eat++;
	p->last_eat_ms = actual_time();
	ft_usleep(p->struc->data.t_eat, p);
	pthread_mutex_unlock(&p->r_fork);
	pthread_mutex_unlock(p->l_fork);
	printf_philo(p, "is sleeping");
	ft_usleep(p->struc->data.t_sleep, p);
	printf_philo(p, "is thinking");
}

void	*philo(void *philo)
{
	t_philo	*p;
	int		n;

	p = (t_philo *)(philo);
	n = 0;
	p->die = 1;
	while (p->struc->all_weat == 0)
	{
		usleep(10);
	}
	if (p->n % 2 != 1)
	{
		printf_philo(p, "is sleeping");
		ft_usleep(p->struc->data.t_sleep, p);
		printf_philo(p, "is thinking");
	}
	while (p->struc->death == 1 && p->nb_eat != p->struc->data.min_nb_eat)
	{
		do_something(p);
	}
	return ((void *)(NULL));
}
