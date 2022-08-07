/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:31:53 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/06 22:20:29 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	action_controller(t_philo	*p)
{
	if (p->status == EATING)
	{
		p->free_forck(p);
		p->status = SLEEPING;
		print_log(p);
	}
	else if (p->status == SLEEPING || p->status == NONE)
	{
		p->status = THINKING;
		print_log(p);
	}
	else if (p->status == THINKING && p->get_forck(p))
	{
		p->status = FORK;
		print_log(p);
		print_log(p);
		p->status = EATING;
		p->eats++;
		p->time_life = get_time() + table()->times[DIED];
		print_log(p);
	}
	p->time = table()->times[p->status];
}

void	*ft_update(void	*philo)
{
	t_philo			*p;

	p = philo;
	while (check_run_table(p))
		;
	p->init_time = table()->init_time;
	p->time_life = p->init_time + table()->times[DIED];
	while (table()->check(p))
	{
		action_controller(p);
		pthread_mutex_unlock(&table()->action);
		ft_usleep(p);
	}
	return (p);
}

t_philo	new_philo(int chair)
{
	t_philo	p;

	p.update = ft_update;
	p.fork = 1;
	p.chair = chair + 1;
	p.eats = 0;
	p.status = THINKING;
	p.is_alive = 1;
	pthread_mutex_init(&p.forck_check, NULL);
	return (p);
}
