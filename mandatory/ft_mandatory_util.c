/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandatory_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:12:56 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/15 13:27:58 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/philo.h"

id_t	check_mandatory(t_status status)
{
	id_t		is_run;

	is_run = 0;
	if (!pthread_mutex_lock(&table()->data.check))
	{
		is_run = table()->data.is_run;
		if (status == DIED)
			table()->data.is_run = false;
		pthread_mutex_unlock(&table()->data.check);
	}
	return (is_run);
}
