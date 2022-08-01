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

#include "philo_bonus.h"


static t_int check_bonus(t_philo *p)
{
	int	i;

	i = 1;
	sem_wait(table()->run_check);
	if (!pthread_mutex_lock(&p->is_alive.mutex))
	{
		i = p->is_alive.value;
		pthread_mutex_unlock(&p->is_alive.mutex);
		if (i)
			sem_post(table()->run_check);
		else
		{
			action(p, DIED);
			sem_post(table()->run_init);
		}
	}
	return (i);
}

static int	ft_get_forck(t_philo *p)
{
	sem_wait(table()->forks);
	sem_wait(table()->forks);
	return (p != NULL);
}

static int	ft_free_forck(t_philo	*p)
{

	sem_post(table()->forks);
	sem_post(table()->forks);
	return (p != NULL);
}

static void	ft_sit(int chair)
{
	t_philo		*p;
	pid_t		pid;

	p = table()->philos[chair];
	p->get_forck = ft_get_forck;
	p->free_forck = ft_free_forck;
	pid = (pthread_t) fork();
	if (pid)
		p->update(p);
	else
	{
		table()->id[chair] = pid;
		table()->id[chair + 1] = -1;
	}
}

void	init_bonus(void)
{
	table()->sit = ft_sit;
	table()->check = check_bonus;

}
