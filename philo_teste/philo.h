/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:53:54 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/06 22:13:35 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "types.h"

//						UTIL
t_useconds				get_time(void);
void					ft_usleep(t_philo	*p);
int						ft_atoi(const char *v);
int						ft_is_number(const char *str);
int						print_log(t_philo	*p);
int						check_run_table(t_philo	*p);

//						TABLE
t_table					*table(void);
void					init_table(int philos, int die, int eat, int sleep);
void					create_link(int size);

//						PHILO
t_philo					new_philo(int chair);
void					*ft_update(void	*philo);
void					action(t_philo	*p, t_status status);

//						MAIN
void					exit_program(void);
int						printf(const char *txt, ...);

//						PROGRAM
int						check_live(t_philo *p, unsigned long long now);

//						MANDATORY
void					init_mandatory(void);

#endif
