/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:31:53 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/05 17:45:06 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	action_controller(t_philo	*p)
{
	if (p->status == NONE)
		p->action(p, THINKING);
	else if (p->status == EATING)
	{
		p->free_forck(p);
		p->action(p, SLEEPING);
	}
	else if (p->status == SLEEPING)
		p->action(p, THINKING);
	if (p->status == THINKING && p->get_forck(p))
	{
		p->action(p, FORK);
		p->action(p, EATING);
		p->time_life = get_time() + table()->times[DIED];
	}
}

void	*ft_update(void	*philo)
{
	t_philo			*p;
	pid_t
	p = philo;
	p->time_life = table()->init_time + table()->times[DIED];
	while (table()->check(p))
		action_controller(p);
	return (p);
}

static void	ft_action(t_philo	*p, t_status status)
{
	if (p->status == status)
		return ;
	p->time = get_time() - table()->init_time;
	printf("%stime: %lu philo: %i action: %s\n", table()->color \
	[status], p->time, p->chair, table()->msg[status]);
	if (status != DIED)
		ft_usleep(table()->times[status], p);
	p->status = status;
}

t_philo	*new_philo(int chair)
{
	t_philo	*p;

	p = malloc_ob(sizeof(t_philo));
	p->update = ft_update;
	p->fork.is_free = 1;
	p->chair = chair + 1;
	p->action = ft_action;
	p->status = NONE;
	p->is_alive = 1;
	pthread_mutex_init(&p->fork.fork, NULL);
	return (p);
}
