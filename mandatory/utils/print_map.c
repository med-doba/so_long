/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:37:34 by med-doba          #+#    #+#             */
/*   Updated: 2022/05/10 19:11:38 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_replace(t_lay *map)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(map->mlx, map->mlx_win);
	while (i < map->height)
	{
		j = 0;
		while (j < map->l)
		{
			if (map->map[i][j] == '1')
				ft_show(map, j, i, "xpmfile/1.xpm");
			else if (map->map[i][j] == '0')
				ft_show(map, j, i, "xpmfile/0.xpm");
			else if (map->map[i][j] == 'P')
				ft_show(map, j, i, "xpmfile/P.xpm");
			else if (map->map[i][j] == 'C')
				ft_show(map, j, i, "xpmfile/C.xpm");
			else if (map->map[i][j] == 'E')
				ft_show(map, j, i, "xpmfile/E.xpm");
			j++;
		}
		i++;
	}
}

void	ft_show(t_lay *map, int i, int j, char *path)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	map->img = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	if (height == 0 || width == 0)
	{
		ft_printf("mlx error\n");
		exit(1);
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, i * 60, j * 60);
}
