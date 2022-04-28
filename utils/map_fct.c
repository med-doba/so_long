/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 16:15:58 by med-doba          #+#    #+#             */
/*   Updated: 2022/04/27 22:26:29 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_rectangular(t_lay *mo)
{
	int	l;
	int	x;
	int	i;

	i = 0;
	l = ft_strlen(mo->map[0]);
	while (i < mo->height)
	{
		if (l != ft_strlen(mo->map[0]))
			x = 0;
		else if (i + 1 < mo->height)
		{
			l = ft_strlen(mo->map[i + 1]);
			x = 1;
		}
		i++;
	}
	return (x);
}

int	ft_walls01(t_lay *mo, char c)
{
	int	i;
	int	j;

	j = 0;
	if (mo->map[0])
	{
		while (mo->map[0][j])
		{
			if (mo->map[0][j] == c)
				j++;
			else if (mo->map[0][j] != c)
				return (0);
		}
	}
	i = 0;
	while (mo->map[i] != NULL)
	{
		if (mo->map[i][0] == c)
			j = 1;
		else
			return (0);
		i++;
	}
	return (j);
}

int	ft_walls02(t_lay *mo, char c)
{
	int	j;
	int	i;
	int	l;

	j = 0;
	while (mo->map[mo->height - 1][j])
	{
		if (mo->map[mo->height - 1][j] == c)
			j++;
		else if (mo->map[mo->height - 1][j] != c)
			return (0);
	}
	i = 0;
	while (mo->map[i] != NULL)
	{
		l = ft_strlen(mo->map[i]);
		if (mo->map[i][l - 1] == c)
			j = 1;
		else
			return (0);
		i++;
	}
	return (j);
}

int	ft_check(t_lay *mo, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (mo->map[i])
	{
		j = 0;
		while (mo->map[i][j])
		{
			if (mo->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	ft_externe(t_lay *mo)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (mo->map[i])
	{
		j = 0;
		while (mo->map[i][j])
		{
			if (mo->map[i][j] != '0' && mo->map[i][j] != 'P'
					&& mo->map[i][j] != 'E' && mo->map[i][j] != 'C'
					&& mo->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
