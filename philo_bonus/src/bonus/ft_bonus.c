/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:12:56 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/20 21:29:51 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>


static t_int check_bonus(t_philo *p)
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
	
	return (is_forck);
}

static int	ft_free_forck(t_philo	*p)
{

	return (1);
}

static void	ft_sit(int chair)
{
	t_philo		*p;

	p = table()->philos[chair];
	p->get_forck = ft_get_forck;
	p->free_forck = ft_free_forck;
	p->thid = (pthread_t) fork();
	if (p->thid)
		p->update(p);
}

void	init_bonus(void)
{
	table()->sit = ft_sit;
	table()->check = check_bonus
	sem_open();
}
