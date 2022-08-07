/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:12:56 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/07 14:12:48 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_int	check_mandatory(t_philo *p)
{
	(void) p;
	pthread_mutex_lock(&table()->action);
	return (table()->is_run);
}

static int	ft_get_forck(t_philo *p)
{
	if (p->fork && p->left->fork)
	{
		p->fork = 0;
		p->left->fork = 0;
		return (1);
	}
	return (0);
}

static int	ft_free_forck(t_philo	*p)
{
	p->fork = 1;
	p->left->fork = 1;
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
