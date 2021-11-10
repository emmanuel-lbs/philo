/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:46:31 by elabasqu          #+#    #+#             */
/*   Updated: 2021/11/09 09:02:49 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	while_dead(t_struct *s)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < s->data.nb_philos)
		{
			if (s->philo[i].nb_eat == s->data.min_nb_eat - 1)
			{
				return (0);
			}
			if (actual_time() - s->philo[i].last_eat_ms > s->data.t_die)
			{
				s->death = 0;
				pthread_mutex_lock(&s->m_write);
				printf("%ld ", actual_time() - s->t_init);
				printf("%d ", i + 1);
				printf("is dead\n");
				pthread_mutex_unlock(&s->m_write);
				return (0);
			}
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	t_struct	s;

	if (!parsing(&s, av, ac))
		return (-1);
	init(&s);
	while_dead(&s);
	sleep(1);
	free(s.philo);
	return (0);
}
