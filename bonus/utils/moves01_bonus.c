/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves01_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:34:06 by med-doba          #+#    #+#             */
/*   Updated: 2022/05/10 19:40:07 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_move_left(t_lay *map, int i, int j)
{
	if (map->map[i][j - 1] == '0')
	{
		map->map[i][j] = '0';
		map->map[i][j - 1] = 'P';
	}
	else if (map->map[i][j - 1] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i][j - 1] = 'P';
	}
	else if (map->map[i][j - 1] == 'E')
	{
		if (ft_check(map, 'C') == 0)
			ft_close(map);
	}
	else if (map->map[i][j - 1] == 'M')
	{
		ft_printf("R.I.P\n");
		ft_close(map);
	}
	ft_replace(map);
	ft_move(map, map->map[i][j - 1]);
	return ;
}

void	ft_left(t_lay *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				ft_move_left(map, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_move_rigth(t_lay *map, int i, int j)
{
	if (map->map[i][j + 1] == '0')
	{
		map->map[i][j] = '0';
		map->map[i][j + 1] = 'P';
	}
	else if (map->map[i][j + 1] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i][j + 1] = 'P';
	}
	else if (map->map[i][j + 1] == 'E')
	{
		if (ft_check(map, 'C') == 0)
			ft_close(map);
	}
	else if (map->map[i][j + 1] == 'M')
	{
		ft_printf("R.I.P\n");
		ft_close(map);
	}
	ft_replace(map);
	ft_move(map, map->map[i][j + 1]);
	return ;
}

void	ft_rigth(t_lay *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				ft_move_rigth(map, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}
