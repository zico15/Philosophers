/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:06:16 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/07 15:06:54 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <pthread.h>
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
	t_int				is_free;
	pthread_mutex_t		fork;
};

typedef struct s_run
{
	t_int				is_run;
	pthread_mutex_t		check;
	pthread_mutex_t		action_get;
	pthread_mutex_t		action_free;
	int					list[999999];
	int					max_eats;
	int					count;
}	t_run;

struct s_philo
{
	pthread_t			thid;
	t_int				chair;
	t_int				is_alive;
	t_status			status;
	t_forck				fork;
	t_philo				*left;
	t_useconds			time;
	t_useconds			init_time;
	t_useconds			time_life;
	int					eats;
	void				*(*update)(void	*p);
	int					(*free_forck)(t_philo *p);
	int					(*get_forck)(t_philo *p);
};

struct s_table
{
	pthread_t		thid;
	t_useconds		init_time;
	int				size;
	char			*msg[6];
	char			*color[6];
	t_useconds		times[6];
	t_philo			philos[9999];
	t_run			run_check;
	pthread_mutex_t	action;
	void			(*sit)(int chair);
	void			(*destroy)();
	t_int			(*check)(t_philo	*p);
};

#endif
