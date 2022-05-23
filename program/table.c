/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:35:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/14 23:31:23 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/philo.h"

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}

static void	destroy(void)
{
	while (table()->size)
		free_ob(table()->philos[--table()->size]);
	free_ob(table()->philos);
}

static void	*ft_update_table(void	*t)
{
	(void) t;
	while (table()->islive)
		;
	exit_program();
	return (0);
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
	table()->size = philos;
	table()->philos = malloc_ob(sizeof(t_philo *) * philos);
	table()->destroy = destroy;
	table()->islive = 1;
	table()->init_time = get_time();
	table()->update = ft_update_table;
	table()->data.is_run = true;
	pthread_mutex_init(&table()->data.check, 0);
	init_table_data(die, eat, sleep);
	philos = -1;
	while (++philos < table()->size)
		table()->philos[philos] = new_philo(philos);
}
