/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:06:16 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/07 16:29:43 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_BONUS_H
# define TYPES_BONUS_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>

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

typedef struct s_run
{
	t_int				is_run;
	pthread_mutex_t		check;
	int					list[999999];
	int					max_eats;
	int					count;
}	t_run;

typedef struct s_live
{
	int					value;
	t_useconds			time_life;
	pthread_mutex_t		mutex;
}	t_live;

struct s_philo
{
	pthread_t			thid;
	int					chair;
	t_live				is_alive;
	t_status			status;
	t_philo				*right;
	t_philo				*left;
	t_useconds			time;
	t_useconds			init_time;
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
	int				max_eats;
	t_useconds		times[6];
	t_philo			philos[9999];
	sem_t			*forks;
	sem_t			*run_check;
	sem_t			*run_init;
	int				id[9999];
	void			(*sit)(int chair);
	void			(*destroy)();
	t_int			(*check)(t_philo	*p);
};

#endif
