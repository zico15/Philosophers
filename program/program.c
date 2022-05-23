/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:24:28 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/21 14:52:03 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/philo.h"

t_useconds	action_controller(t_philo	*p, t_useconds time)
{
	if (p->status == NONE)
		return (p->action(p, THINKING, time));
	else if (p->status == EATING)
	{
		p->free_forck(p);
		return (p->action(p, SLEEPING, time));
	}
	else if (p->status == SLEEPING)
		return (p->action(p, THINKING, time));
	if (p->status == THINKING && p->get_forck(p))
	{
		time = p->action(p, FORK, time);
		time = p->action(p, EATING, time);
	}
	return (get_time());
}

t_useconds	action_controller2(t_philo	*p)
{
	if (p->status == NONE)
		p->action(p, THINKING, p->time_init);
	else if (p->status == EATING)
	{
		p->free_forck(p);
		p->action(p, SLEEPING, p->time_init);
	}
	else if (p->status == SLEEPING)
		p->action(p, THINKING, p->time_init);
	if (p->status == THINKING && p->get_forck(p))
	{
		p->action(p, FORK, p->time_init);
		p->action(p, EATING, p->time_init);
		p->time = 0;
	}
	return (table()->times[p->status]);
}
