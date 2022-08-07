/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:31:53 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/07 16:47:35 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action(t_philo	*p, t_status status)
{
	if (p->status == status && !table()->check(p))
		return ;
	printf("%stime: %lu philo: %i action: %s\n", table()->color \
	[status], (get_time() - table()->init_time), \
	p->chair, table()->msg[status]);
	if (status == FORK)
		printf("%stime: %lu philo: %i action: %s\n", table()->color \
		[status], (get_time() - table()->init_time), \
		p->chair, table()->msg[status]);
	if (status != DIED)
		ft_usleep(table()->times[status], p);
	p->status = status;
}

static void	action_controller(t_philo	*p)
{
	if (p->status == NONE)
		action(p, THINKING);
	else if (p->status == EATING)
	{
		p->free_forck(p);
		action(p, SLEEPING);
	}
	else if (p->status == SLEEPING)
		action(p, THINKING);
	if (p->status == THINKING && p->get_forck(p))
	{
		action(p, FORK);
		action(p, EATING);
		p->eats++;
		p->time_life = get_time() + table()->times[DIED];
	}
}

void	*ft_update(void	*philo)
{
	t_philo			*p;

	p = philo;
	p->time_life = get_time() + table()->times[DIED];
	while (table()->check(p))
		action_controller(p);
	return (p);
}

t_philo	new_philo(int chair)
{
	t_philo	p;

	p.update = ft_update;
	p.fork.is_free = 1;
	p.chair = chair + 1;
	p.eats = 0;
	p.status = THINKING;
	p.is_alive = 1;
	pthread_mutex_init(&p.fork.fork, NULL);
	return (p);
}
