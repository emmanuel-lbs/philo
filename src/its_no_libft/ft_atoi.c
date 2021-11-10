/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <elabasqu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:25:34 by elabasqu          #+#    #+#             */
/*   Updated: 2021/11/04 17:41:30 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

static int	ft_ispaces(const char *chaine)
{
	int	i;

	i = 0;
	while (chaine[i] == '\t'
		|| chaine[i] == '\n'
		|| chaine[i] == '\v'
		|| chaine[i] == ' '
		|| chaine[i] == '\f'
		|| chaine[i] == '\r')
		i++;
	return (i);
}

long int	ft_atoi(const char *str)
{
	long int	le_int;
	int			sign;
	int			i;

	le_int = 0;
	sign = 1;
	i = ft_ispaces(str);
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		le_int = le_int * 10 + (str[i] - 48);
		i++;
	}
	if (le_int > 9223372036854775807 && sign == -1)
		return (0);
	else if (le_int > 9223372036854775807 && sign == 1)
		return (-1);
	return (le_int * sign);
}
