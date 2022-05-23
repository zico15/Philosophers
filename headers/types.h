/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:06:16 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/21 14:19:40 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>

# define MILLISECONDS	1000
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct s_philo		t_philo;
typedef char				t_int;
typedef struct s_table		t_table;
typedef struct s_forck		t_forck;
typedef unsigned long		t_useconds;

typedef enum e_boolean
{
	false,
	true
}	t_boolean;

typedef enum e_status
{
	FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	NONE
}	t_status;

struct s_forck
{
	id_t				is_select;
	pthread_mutex_t		fork;
};

typedef struct s_run
{
	id_t				is_run;
	pthread_mutex_t		check;
}	t_run;

struct s_philo
{
	pthread_t			thid;
	int					chair;
	t_int				islive;
	t_useconds			died;
	t_useconds			time;
	t_useconds			time_init;
	t_useconds			time_end;
	t_useconds			times[6];
	t_status			status;
	t_forck				fork;
	t_useconds			action_time;
	int					correcao;
	int					is_action;
	void				*(*update)(void	*p);
	int					(*free_forck)(t_philo *p);
	int					(*get_forck)(t_philo *p);
	t_useconds			(*action)(t_philo *p, t_status status, t_useconds time);
};

struct s_table
{
	pthread_t		thid;
	t_useconds		init_time;
	int				size;
	t_int			islive;
	int				number_of_times_each_philosopher_must_eat;
	char			*msg[6];
	char			*color[6];
	t_useconds		times[6];
	int				is_init;
	t_philo			**philos;
	t_forck			**forks;
	t_run			data;
	void			(*sit)(int chair);
	void			*(*update)(void	*table);
	void			(*destroy)();
	id_t			(*check)(t_status status);
};

#endif
