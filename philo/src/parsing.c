/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:51:11 by elabasqu          #+#    #+#             */
/*   Updated: 2021/11/06 18:02:05 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	print_and_return(char *s, int ret)
{
	printf("%s", s);
	return (ret);
}

static long int	get_value(char *str)
{
	long int	nb;
	char		*nbr;

	nb = ft_atoi(str);
	if (nb > INT_MAX)
		exit(print_and_return("Error\n don't put overflowww\n", -1));
	nbr = ft_itoa(nb);
	if (ft_strncmp(str, nbr, ft_strlen(str)))
	{
		free (nbr);
		exit(print_and_return("Error\nuno nbr its not valid\n", -1));
	}
	else
	{
		free (nbr);
		if (nb <= 0)
			exit(print_and_return("Error\narguments must be > 0\n", -1));
		return (nb);
	}
}

static void	init_struct(t_struct *s, char **av, int ac)
{
	s->data.nb_philos = get_value(av[1]);
	s->data.t_die = get_value(av[2]);
	s->data.t_eat = get_value(av[3]);
	s->data.t_sleep = get_value(av[4]);
	if (ac == 6)
		s->data.min_nb_eat = get_value(av[5]);
	else
		s->data.min_nb_eat = -1;
}

void	print_data(t_struct *s)
{
	printf("%ld\n", s->data.nb_philos);
	printf("%ld\n", s->data.t_die);
	printf("%ld\n", s->data.t_eat);
	printf("%ld\n", s->data.t_sleep);
	if (s->data.min_nb_eat > 0)
		printf("%ld\n", s->data.min_nb_eat);
}

int	parsing(t_struct *s, char **av, int ac)
{
	if (ac < 5 || ac > 6)
		return (print_and_return("Error\nnumbers of argument\n", -1));
	init_struct(s, av, ac);
	return (1);
}
