/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:31:53 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/20 21:09:47 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	action(t_philo	*p, t_status status)
{
	if (p->status == status && !table()->check(p))
		return ;
	printf("%s time: %lu philo: %i action: %s\n", table()->color \
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
		if (!pthread_mutex_lock(&p->is_alive.mutex))
		{
			p->is_alive.time_life = get_time() + table()->times[DIED];
			pthread_mutex_unlock(&p->is_alive.mutex);
		}
	}
}

static void *check_live(void *philo)
{
	t_philo			*p;

	p = philo;
	while (table()->check(p))
	{
		if (p->is_alive.value && get_time() > p->is_alive.time_life)
		{
			p->is_alive.value = 0;
		}
		usleep(10);
	}
	return (p);
}

void	*ft_update(void	*philo)
{
	t_philo			*p;

	p = philo;
	if (!pthread_mutex_lock(&p->is_alive.mutex))
	{
		p->is_alive.time_life = get_time() + table()->times[DIED];
		pthread_mutex_unlock(&p->is_alive.mutex);
	}
	if (pthread_create(&p->thid, NULL, check_live, p) == 0)
	{
		while (table()->check(p))
			action_controller(p);
	}
	return (p);
}

t_philo	*new_philo(int chair)
{
	t_philo	*p;

	p = malloc_ob(sizeof(t_philo));
	p->update = ft_update;
	p->chair = chair + 1;
	p->eats = 0;
	p->status = NONE;
	p->is_alive.value = 1;
	pthread_mutex_init(&p->is_alive.mutex, NULL);
	return (p);
}
