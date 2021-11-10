/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:32:33 by elabasqu          #+#    #+#             */
/*   Updated: 2021/11/06 15:36:15 by elabasqu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include "philo.h"

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~CAST_STRUCT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
typedef struct struc	t_struct;
typedef struct timeval	t_timeval;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~STRUCT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
typedef struct data {
	long int	nb_philos;
	long int	t_die;
	long int	t_eat;
	long int	t_sleep;
	long int	min_nb_eat;
}				t_data;

typedef struct s_philo {
	long int		last_eat_ms;
	unsigned int	nb_eat;
	int				n;
	int				die;

	t_struct		*struc;
	pthread_t		thread;
	pthread_mutex_t	r_fork;
	pthread_mutex_t	*l_fork;
}				t_philo;

typedef struct struc {
	t_philo			*philo;
	t_data			data;

	int				death;
	int				all_weat;
	long int		t_init;
	t_timeval		t_now;
	pthread_mutex_t	m_write;
}				t_struct;

#endif
