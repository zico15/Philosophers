/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:12:56 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/21 13:16:34 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/philo.h"

static int	get_proxi(t_philo	*p)
{
	int	i;

	i = p->chair;
	if (i >= table()->size)
		i = 0;
	if (table()->size == 1)
		i = __INT_MAX__;
	return (i);
}

static int	ft_get_forck(t_philo *p)
{
	int	i;
	int	is_forck;

	i = get_proxi(p);
	is_forck = 0;
	if (i < table()->size && \
	!pthread_mutex_lock(&table()->philos[i]->fork.fork))
	{
		if (table()->philos[i]->fork.is_select == false)
		{
			if (!pthread_mutex_lock(&p->fork.fork))
			{
				if (p->fork.is_select == false)
				{
					p->fork.is_select = true;
					table()->philos[i]->fork.is_select = true;
					is_forck = true;
				}
				pthread_mutex_unlock(&p->fork.fork);
			}
		}
		pthread_mutex_unlock(&table()->philos[i]->fork.fork);
	}
	return (is_forck);
}

static int	ft_free_forck(t_philo	*p)
{
	int	i;

	i = get_proxi(p);
	if (i < table()->size && \
	!pthread_mutex_lock(&table()->philos[i]->fork.fork))
	{
		table()->philos[i]->fork.is_select = false;
		if (!pthread_mutex_lock(&p->fork.fork))
		{
			p->fork.is_select = false;
			pthread_mutex_unlock(&p->fork.fork);
		}
		pthread_mutex_unlock(&table()->philos[i]->fork.fork);
	}
	return (true);
}

static void	ft_sit(int chair)
{
	t_philo		*p;

	p = table()->philos[chair];
	p->get_forck = ft_get_forck;
	p->free_forck = ft_free_forck;
	if (!p || pthread_create(&p->thid, NULL, p->update, p) != 0)
		exit_program();
}

void	init_mandatory(void)
{
	table()->sit = ft_sit;
	table()->check = check_mandatory;
}
