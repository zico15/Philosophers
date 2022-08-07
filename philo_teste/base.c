/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:26:54 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/06 21:24:29 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_useconds	get_time(void)
{
	struct timeval	te;

	gettimeofday(&te, NULL);
	return (te.tv_sec * MILLISECONDS + te.tv_usec / MILLISECONDS);
}

/*
struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000)
*/
void	ft_usleep(t_philo	*p)
{
	t_useconds	t;

	t = get_time() + (p->time);
	if (p->time <= 0)
		return ;
	while (get_time() < t)
		usleep(10);
}

t_useconds	get_time_now(t_useconds start)
{
	return (get_time() - start);
}

int	print_log(t_philo	*p)
{
	printf("%stime: %lu philo: %i action: %s\n", table()->color \
	[p->status], (get_time() - p->init_time), \
	p->chair, table()->msg[p->status]);
	return (1);
}
