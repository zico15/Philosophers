/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:24:28 by edos-san          #+#    #+#             */
/*   Updated: 2022/06/16 17:14:23 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/philo.h"

t_useconds	action_controller(t_philo	*p)
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
		p->time_eat = get_time() + table()->times[DIED];
	}
	return (table()->times[p->status]);
}
