/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezequeil <ezequeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:15:49 by edos-san          #+#    #+#             */
/*   Updated: 2022/07/05 17:33:34 by ezequeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	free_ob(void *v)
{
	if (v == NULL)
		return (1);
	free(v);
	return (1);
}

int	free_list(char **str)
{
	int		i;

	if (str)
	{
		i = -1;
		while (str[++i])
			free_ob(str[i]);
		free_ob(str);
		return (i);
	}
	return (0);
}

void	*malloc_ob(size_t __size)
{
	void			*v;
	unsigned char	*temp;

	if (__size < 1)
		return (NULL);
	v = malloc(__size);
	if (!v)
		exit_program();
	temp = (unsigned char *) v;
	while (__size-- > 0)
		*(temp++) = (unsigned char) 0;
	return (v);
}

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
