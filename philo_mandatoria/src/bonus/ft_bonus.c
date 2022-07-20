/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:12:56 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/13 18:21:12 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/philo.h"

static void	ft_sit(int chair)
{
	t_philo		*p;

	p = table()->philos[chair];
	if (!p || pthread_create(&p->thid, NULL, p->update, p) != 0)
		exit_program();
}

void	init_bonus(void)
{
	table()->sit = ft_sit;
}
