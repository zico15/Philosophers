/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:26:54 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/16 17:26:00 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/philo.h"

int	free_ob(void *v)
{
	printf("free_ob\n");
	if (v)
	{
		free(v);
		return (true);
	}
	return (false);
}

void	*malloc_ob(int size)
{
	void	*v;

	v = malloc(size);
	if (!v)
		exit_program();
	return (v);
}

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

	t = get_time();
	if (t > p->time_eat)
		p->action(p, DIED, get_time_now(table()->init_time));
	if (time <= 0)
		return ;
	while (get_time() - t < time && table()->check(p->status))
	{
		if (get_time() > p->time_eat)
		{
			p->action(p, DIED, get_time_now(table()->init_time));
			p->islive = false;
			return ;
		}
		usleep(1);
	}
}

t_useconds	get_time_now(t_useconds start)
{
	return (get_time() - start);
}

int	is_loop(void)
{
	int	i;

	i = -1;
	while (++i < table()->size)
		if (!table()->philos[i]->islive)
			return (false);
	return (table()->philos != false);
}
