/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:35:32 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/05 15:43:02 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	create_link(int size)
{
	int			i;
	t_philo		*p;
	t_philo		*b;

	b = table()->philos[0];
	p = b;
	i = 1;
	while (i < size)
	{
		p->left = table()->philos[i];
		p = table()->philos[i++];
	}
	p->left = b;
}
