/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:33:13 by med-doba          #+#    #+#             */
/*   Updated: 2022/05/10 17:48:17 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_move(t_lay *map)
{
	(map->move)++;
	ft_printf("move : %d\n", map->move);
}

void	ft_move_up(t_lay *map, int i, int j)
{
	if (map->map[i - 1][j] == '0')
	{
		map->map[i][j] = '0';
		map->map[i - 1][j] = 'P';
	}
	else if (map->map[i - 1][j] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i - 1][j] = 'P';
	}
	else if (map->map[i - 1][j] == 'E')
	{
		if (ft_check(map, 'C') == 0)
		{
			ft_printf("You Win\n");
			ft_close(map);
		}
	}
	ft_replace(map);
	if (map->map[i - 1][j] != 'E' && map->map[i - 1][j] != '1')
		ft_move(map);
	return ;
}

void	ft_up(t_lay *map)
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
				ft_move_up(map, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ft_move_down(t_lay *map, int i, int j)
{
	if (map->map[i + 1][j] == '0')
	{
		map->map[i][j] = '0';
		map->map[i + 1][j] = 'P';
	}
	else if (map->map[i + 1][j] == 'C')
	{
		map->map[i][j] = '0';
		map->map[i + 1][j] = 'P';
	}
	else if (map->map[i + 1][j] == 'E')
	{
		if (ft_check(map, 'C') == 0)
		{
			ft_printf("You Win\n");
			ft_close(map);
		}
	}
	ft_replace(map);
	if (map->map[i + 1][j] != '1' && map->map[i + 1][j] != 'E')
		ft_move(map);
	return ;
}

void	ft_down(t_lay *map)
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
				ft_move_down(map, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}
