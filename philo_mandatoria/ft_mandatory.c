/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:12:56 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/07 14:29:51 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_int	check_mandatory(t_philo *p)
{
	int			i;

	if (!pthread_mutex_lock(&table()->run_check.check))
	{
		table()->run_check.list[p->chair - 1] = p->eats;
		i = -1;
		table()->run_check.count = table()->run_check.max_eats;
		while (table()->run_check.is_run && \
		table()->run_check.count > 0 && ++i < table()->size)
		{
			if (table()->run_check.list[i] < table()->run_check.max_eats)
				table()->run_check.count = 0;
		}
		if (table()->run_check.is_run && table()->run_check.count > 0)
			table()->run_check.is_run = 0;
		if (table()->run_check.is_run && get_time() >= p->time_life)
		{
			action(p, DIED);
			table()->run_check.is_run = 0;
		}
		pthread_mutex_unlock(&table()->run_check.check);
	}
	return (table()->run_check.is_run);
}

static int	ft_get_forck(t_philo *p)
{
	int	is_forck;

	is_forck = 0;
	pthread_mutex_lock(&table()->action);
	if (!pthread_mutex_lock(&(p->left)->fork.fork))
	{
		if ((p->left)->fork.is_free)
		{	
			if (!pthread_mutex_lock(&p->fork.fork))
			{
				if (p->fork.is_free)
				{
					p->fork.is_free = 0;
					(p->left)->fork.is_free = 0;
					is_forck = 1;
				}
				pthread_mutex_unlock(&p->fork.fork);
			}
		}
		pthread_mutex_unlock(&(p->left)->fork.fork);
	}
	pthread_mutex_unlock(&table()->action);
	return (is_forck);
}

static int	ft_free_forck(t_philo	*p)
{
	pthread_mutex_lock(&table()->action);
	if (!pthread_mutex_lock(&p->fork.fork))
	{
		if (!pthread_mutex_lock(&(p->left)->fork.fork))
		{
			p->fork.is_free = 1;
			(p->left)->fork.is_free = 1;
			pthread_mutex_unlock(&(p->left)->fork.fork);
		}
		pthread_mutex_unlock(&p->fork.fork);
	}
	pthread_mutex_unlock(&table()->action);
	return (1);
}

static void	ft_sit(int chair)
{
	t_philo		*p;

	p = &table()->philos[chair];
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
