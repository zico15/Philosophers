/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:50:11 by edos-san          #+#    #+#             */
/*   Updated: 2022/05/21 14:47:32 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/philo.h"

int	test_leaks(int is_test)
{
	if (is_test)
		system("leaks -- philo");
	return (1);
}

void	exit_program(void)
{
	int	i;

	i = -1;
	while (++i < table()->size)
		pthread_mutex_destroy(&table()->philos[i]->fork.fork);
	exit(0);
}

int	main(int argc, char **argv)
{
	int				size;
	int				i;

	size = 2;
	i = -1;
	if (argc <= 1 && argv)
	{
		printf("\n");
	}
	init_mandatory();
	init_table(size, 400, 200, 200);
	printf("init_table\n");
	while (++i < size)
		table()->sit(i);
	pthread_join((table()->philos[0])->thid, 0);
	exit_program();
	return (test_leaks(0));
}
