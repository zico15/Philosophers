/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:26:54 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/21 15:02:18 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/philo.h"

int	free_ob(void *v)
{
	printf("free_ob\n");
	if (v)
	{
		free(v);
		return (true);
	}
	return (false);
}

void	*malloc_ob(int size)
{
	void	*v;

	v = malloc(size);
	if (!v)
		exit_program();
	return (v);
}

t_useconds	get_time(void)
{
	struct timeval	te;

	gettimeofday(&te, NULL);
	return ((te.tv_sec * 1000) + (te.tv_usec / 1000));
}

t_useconds	usleep_ob(t_useconds delay, t_philo *p)
{
	t_useconds	end;

	end = get_time() + (delay);
	(void) p;
	while (delay > 0 && get_time() < end)
		;
	return (get_time());
}

int	is_loop(void)
{
	int	i;

	i = -1;
	while (++i < table()->size)
		if (!table()->philos[i]->islive)
			return (false);
	return (table()->philos != false);
}
