/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:26:54 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/20 20:59:39 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
void	ft_usleep(t_useconds time, t_philo	*p)
{
	t_useconds	t;

	t = get_time() + (time);
	if (time <= 0)
		return ;
	while (get_time() < t && table()->check(p))
		usleep(1);
}

t_useconds	get_time_now(t_useconds start)
{
	return (get_time() - start);
}
