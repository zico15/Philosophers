/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:15:49 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/06 22:07:58 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

int	ft_atoi(const char *v)
{
	int			i;
	long int	n;

	n = 0;
	if (!v)
		return (0);
	i = (v[0] != '-') - (v[0] == '-');
	while (*v)
	{
		if (*v != '-' && *v != '+')
			n = (n * 10) + (*v - '0');
		v++;
	}
	return (n * i);
}

int	ft_is_number(const char *str)
{
	while (str && *str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
