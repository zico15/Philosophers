/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:35:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/06 22:20:17 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}

static void	destroy(void)
{
	printf("ERROR NUMBER MAX PHILOS!\n");
	exit(0);
}

static void	init_table_data(int die, int eat, int sleep)
{
	table()->times[FORK] = 0;
	table()->times[EATING] = eat;
	table()->times[SLEEPING] = sleep;
	table()->times[THINKING] = 0;
	table()->times[DIED] = die;
	table()->times[NONE] = 0;
	table()->msg[FORK] = "has taken a fork";
	table()->msg[EATING] = "is eating";
	table()->msg[SLEEPING] = "is sleeping";
	table()->msg[THINKING] = "is thinking";
	table()->msg[DIED] = "died";
	table()->msg[NONE] = "none";
	table()->color[0] = KNRM;
	table()->color[1] = KBLU;
	table()->color[2] = KCYN;
	table()->color[3] = KGRN;
	table()->color[4] = KMAG;
	table()->color[5] = KNRM;
}

void	init_table(int philos, int die, int eat, int sleep)
{
	if (philos >= 9999)
		destroy();
	table()->size = philos;
	table()->destroy = destroy;
	table()->init_time = get_time();
	table()->is_run = 0;
	pthread_mutex_init(&table()->action, NULL);
	pthread_mutex_init(&table()->init, NULL);
	init_table_data(die, eat, sleep);
	philos = -1;
	while (++philos < table()->size)
	{
		table()->philos[philos] = new_philo(philos);
		table()->philos[philos + 1].fork = 0;
	}
	create_link(table()->size);
}

int	check_run_table(t_philo	*p)
{
	int	i;

	pthread_mutex_lock(&table()->init);
	if (p->chair == table()->size)
	{
		table()->init_time = get_time();
		table()->is_run = 1;
	}
	i = table()->is_run;
	pthread_mutex_unlock(&table()->init);
	return (!i);
}
