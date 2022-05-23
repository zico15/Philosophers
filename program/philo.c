/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:31:53 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/21 15:00:44 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/philo.h"

void	*ft_update(void	*philo)
{
	t_philo			*p;
	t_useconds		time_start;

	p = philo;
	time_start = get_time();
	//printf("%i - time_start: %lu", p->chair, time_start);
	p->time_init = time_start;
	p->is_action = false;
	while (p->time < table()->times[DIED] && table()->check(p->status))
	{
		p->time = get_time() - time_start;
		if (p->time == table()->times[p->status])
			time_start = action_controller(p, time_start);
		if (!time_start)
			break ;
	}
	if (time_start)
		p->action(p, DIED, time_start);
	exit_program();
	return (0);
}

void	*ft_update2(void	*philo)
{
	t_philo			*p;
	t_useconds		seg;

	p = philo;
	p->time_init = get_time();
	p->action_time = p->time_init;
	while (table()->check(p->status))
	{
		seg = action_controller2(p);
	}
	exit_program();
	return (0);
}

static t_useconds	ft_action(t_philo	*p, t_status status, t_useconds time)
{
	t_useconds	t;
	id_t		is_run;

	if (p->status == status)
		return (time);
	is_run = table()->check(status);
	if (!is_run)
		return (0);
	p->is_action = false;
	t = (p->action_time - p->time_init);
	printf("%stime: %lu philo: %i action: %s\n", table()->color \
	[status], t, p->chair, table()->msg[status]);
	p->status = status;
	p->action_time = usleep_ob(table()->times[status], p);
	return (get_time());
}

t_philo	*new_philo(int chair)
{
	t_philo	*p;

	p = malloc_ob(sizeof(t_philo));
	if (!p)
		return (0);
	p->update = ft_update2;
	p->thid = 0;
	p->time = 0;
	p->fork.is_select = false;
	p->chair = chair + 1;
	p->action = ft_action;
	p->status = NONE;
	p->thid = NULL;
	p->status = NONE;
	p->islive = 1;
	pthread_mutex_init(&p->fork.fork, 0);
	p->died = table()->times[DIED];
	return (p);
}
