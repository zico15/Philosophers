/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:06:16 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/05 17:07:48 by ezequeil         ###   ########.fr       */
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
	id_t				is_free;
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
	int					is_alive;
	t_status			status;
	t_forck				fork;
	t_philo				*left;
	t_useconds			time;
	t_useconds			time_life;
	void				*(*update)(void	*p);
	int					(*free_forck)(t_philo *p);
	int					(*get_forck)(t_philo *p);
	void				(*action)(t_philo *p, t_status status);
};

struct s_table
{
	pthread_t		thid;
	t_useconds		init_time;
	int				size;
	char			*msg[6];
	char			*color[6];
	t_useconds		times[6];
	t_philo			**philos;
	t_run			run_check;
	void			(*sit)(int chair);
	void			*(*update)(void	*table);
	void			(*destroy)();
	id_t			(*check)(t_philo	*p);
};

#endif
