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

#include <philo_bonus.h>


static t_int check_bonus(t_philo *p)
{
	sem_wait(table()->run_check);
	if (p->is_alive)
	{
		sem_post(table()->run_check);
		return (1);
	}
	return (0);
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
	table()->check = check_bonus;

}
