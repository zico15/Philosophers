/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:53:54 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/20 21:27:33 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "types_bonus.h"
# include <sys/time.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/wait.h>

//						UTIL
int						free_ob(void *v);
void					*malloc_ob(size_t size);
t_useconds				get_time(void);
void					ft_usleep(t_useconds time, t_philo	*p);
int						ft_atoi(const char *v);
int						ft_is_number(const char *str);

//						TABLE
t_table					*table(void);
void					init_table(int philos, int die, int eat, int sleep);
void					create_link(int size);

//						PHILO
t_philo					*new_philo(int chair);
void					*ft_update(void	*philo);
void					action(t_philo	*p, t_status status);

//						MAIN
void					exit_program(void);

//						BONUS
void	                init_bonus(void);

#endif
