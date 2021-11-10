/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:30:50 by elabasqu          #+#    #+#             */
/*   Updated: 2021/11/09 09:03:56 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>
# include "structure.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ITS_NOT_A_LIBFT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
long int	ft_atoi(const char *str);
char		*ft_itoa(long int a);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~UTILS~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int			parsing(t_struct *s, char **av, int ac);
void		ft_usleep(long int ms, t_philo *p);
long int	actual_time(void);
void		init(t_struct *s);
void		*philo(void *philo);

#endif
