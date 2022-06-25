/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:31:53 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/16 17:27:20 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/philo.h"

void	*ft_update(void	*philo)
{
	t_philo			*p;
	t_useconds		action;

	p = philo;
	p->time_init = 0;
	action = 0;
	p->time_eat = get_time() + table()->times[DIED];
	while (p->islive)
	{
		p->time_init = get_time_now(table()->init_time);
		action = action_controller(p);
		ft_usleep(action, p);
	}
	exit_program();
	return (0);
}

static void	ft_action(t_philo	*p, t_status status, t_useconds time)
{

	if (p->status == status)
		return ;
	p->islive = table()->check(status);
	if (!p->islive)
		return ;
	p->is_action = false;
	printf("%stime: %lu philo: %i action: %s\n", table()->color \
	[status], time, p->chair, table()->msg[status]);
	p->status = status;
}

t_philo	*new_philo(int chair)
{
	t_philo	*p;

	p = malloc_ob(sizeof(t_philo));
	if (!p)
		return (0);
	p->update = ft_update;
	p->thid = 0;
	p->fork.is_select = false;
	p->chair = chair + 1;
	p->action = ft_action;
	p->time_eat = 0;
	p->status = NONE;
	p->thid = NULL;
	p->status = NONE;
	p->islive = 1;
	pthread_mutex_init(&p->fork.fork, 0);
	p->died = table()->times[DIED];
	return (p);
}
