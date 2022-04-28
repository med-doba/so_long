/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:34:06 by med-doba          #+#    #+#             */
/*   Updated: 2022/04/27 22:57:22 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_move_left(t_lay *map, int *i, int *j)
{
	if (map->map[*i][*j - 1] == '0')
	{
		map->map[*i][*j] = '0';
		map->map[*i][*j - 1] = 'P';
	}
	else if (map->map[][] == 'C')
	{
		map->map[*i][*j] = '0';
		map->map[*i][*j - 1] = 'P';
	}
	else if (map->map[*i][*j - 1] == 'E')
	{
		if (ft_check(map, 'C') == 0)
			exit(0);
	}
	return ;
}

void ft_move_up(t_lay *map, int *i, int *j)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] == NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				ft_move_left(map, &i, &j);
				return ;
			}
			j++;
		}
		i++;
	}
}

void ft_move_rigth(t_lay *map, int *i, int *j)
{
	if (map->map[*i][*j + 1] == '0')
	{
		map->map[*i][*j] = '0';
		map->map[*i][*j + 1] = 'P';
	}
	else if (map->map[][] == 'C')
	{
		map->map[*i][*j] = '0';
		map->map[*i][*j + 1] = 'P';
	}
	else if (map->map[*i][*j + 1] == 'E')
	{
		if (ft_check(map, 'C') == 0)
			exit(0);
	}
	return ;
}

void	ft_rigth(t_lay *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] == NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				ft_move_rigth(map, &i, &j);
				return ;
			}
			j++;
		}
		i++;
	}
}
