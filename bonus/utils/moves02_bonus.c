/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves02_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:33:13 by med-doba          #+#    #+#             */
/*   Updated: 2022/05/10 19:41:43 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_move(t_lay *map, char c)
{
	char	*tab;

	if (c != 'E' && c != '1')
		(map->move)++;
	tab = ft_itoa(map->move);
	mlx_string_put(map->mlx, map->mlx_win, 0, 0, 0x00FF0000, "Moves : ");
	mlx_string_put(map->mlx, map->mlx_win, 60, 0, 0x00FF0000, tab);
	free(tab);
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
			ft_close(map);
	}
	else if (map->map[i - 1][j] == 'M')
	{
		ft_printf("R.I.P\n");
		ft_close(map);
	}
	ft_replace(map);
	ft_move(map, map->map[i - 1][j]);
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
			ft_close(map);
	}
	else if (map->map[i + 1][j] == 'M')
	{
		ft_printf("R.I.P\n");
		ft_close(map);
	}
	ft_replace(map);
	ft_move(map, map->map[i + 1][j]);
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
