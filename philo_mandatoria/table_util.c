/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:35:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/07 16:46:58 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_link(int size)
{
	int			i;
	t_philo		*p;
	t_philo		*b;

	i = 0;
	b = &table()->philos[0];
	if (size == 1)
	{
		b->left = &table()->philos[i++];
		b->left->fork.is_free = 0;
		return ;
	}
	p = b;
	i = 1;
	while (i < size)
	{
		p->left = &table()->philos[i];
		p = &table()->philos[i++];
	}
	p->left = b;
}
