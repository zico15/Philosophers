/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:50:11 by edos-san          #+#    #+#             */
/*   Updated: 2022/08/07 15:34:39 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	exit_program(void)
{
	int	i;

	i = -1;
	while (++i < table()->size)
	{
		pthread_mutex_destroy(&table()->philos[i].is_alive.mutex);
		kill(table()->id[i], SIGINT);
	}
	printf("\033[0m");
	exit(0);
}

int	check_args(int argc, const char **argv)
{
	if (argc <= 4)
		return (0);
	argv++;
	while (*argv)
	{
		if (!ft_is_number(*argv))
			return (0);
		argv++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int				size;
	int				i;

	i = -1;
	if (!check_args(argc, (const char **) argv))
		return (0);
	init_bonus();
	size = ft_atoi(argv[1]);
	init_table(size, ft_atoi(argv[2]), ft_atoi(argv[3]), ft_atoi(argv[4]));
	if (argc > 5)
		table()->max_eats = ft_atoi(argv[5]);
	else
		table()->max_eats = -1;
	while (++i < size)
		table()->sit(i);
	i = -1;
	while (++i < size)
		sem_wait(table()->run_init);
	exit_program();
	return (1);
}
