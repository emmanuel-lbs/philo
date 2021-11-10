/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:31:15 by elabasqu          #+#    #+#             */
/*   Updated: 2021/11/09 08:57:57 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	init_mutex(t_struct *s)
{
	int	i;

	i = 0;
	pthread_mutex_init(&s->m_write, NULL);
	while (i < s->data.nb_philos)
	{
		s->philo[i].struc = s;
		s->philo[i].nb_eat = 0;
		s->philo[i].last_eat_ms = actual_time();
		pthread_mutex_init(&s->philo[i].r_fork, NULL);
		if (i == 0)
			s->philo[0].l_fork = &s->philo[s->data.nb_philos - 1].r_fork;
		else
			s->philo[i].l_fork = &s->philo[i - 1].r_fork;
		i++;
	}
}

static void	init_thread(t_struct *s)
{
	int	i;

	i = -1;
	while (++i < s->data.nb_philos)
	{
		s->philo[i].n = i;
		pthread_create(&s->philo[i].thread, NULL, philo, &s->philo[i]);
	}
}

void	init(t_struct *s)
{
	s->philo = malloc(sizeof(s->philo) * s->data.nb_philos);
	s->all_weat = 0;
	s->death = 1;
	init_mutex(s);
	init_thread(s);
	s->t_init = actual_time();
	s->all_weat = 1;
}
