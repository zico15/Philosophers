/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:53:54 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/20 19:43:56 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "types.h"
# include <sys/time.h>
# include <unistd.h>

//						BASE
int						free_ob(void *v);
void					*malloc_ob(int size);
t_useconds				get_time(void);
int						is_loop(void);
t_useconds				usleep_ob(t_useconds delay, t_philo *p);

//						TABLE
t_table					*table(void);
void					init_table(int philos, int die, int eat, int sleep);

//						PHILO
t_philo					*new_philo(int chair);
void					*ft_update(void	*philo);

//						MAIN
void					exit_program(void);

//						PROGRAM
t_useconds				action_controller(t_philo	*p, t_useconds time_start);
t_useconds				action_controller2(t_philo	*p);
int						check_live(t_philo *p, unsigned long long now);

//						MANDATORY
void					init_mandatory(void);
id_t					check_mandatory(t_status status);
#endif
