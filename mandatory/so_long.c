/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 02:42:02 by med-doba          #+#    #+#             */
/*   Updated: 2022/05/10 19:42:10 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close(t_lay *map)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
	exit(1);
}

int	key_hook(int keycode, t_lay *map)
{
	if (keycode == 53)
		ft_close(map);
	if (keycode == 13)
		ft_up(map);
	else if (keycode == 1)
		ft_down(map);
	else if (keycode == 0)
		ft_left(map);
	else if (keycode == 2)
		ft_rigth(map);
	return (0);
}

void	ft_check_mlx(t_lay *map)
{
	if (map->mlx == NULL)
		ft_close(map);
}

int	close1(t_lay *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	ft_printf("game over\n");
	ft_close(map);
	return (0);
}

int	main(int ac, char *av[])
{
	t_lay	*map;

	map = (t_lay *)malloc(sizeof(t_lay) * 1);
	if (map == NULL)
		return (1);
	map->move = 0;
	if (ac != 2)
		return (perror("warning,only the first one will be used"), 1);
	if (ft_extention(av[1]) == 1)
	{
		ft_read(av[1], map);
		map->mlx = mlx_init();
		ft_check_mlx(map);
		map->mlx_win = mlx_new_window(map->mlx, map->l * 60,
				map->height * 60, "so_long");
		ft_replace(map);
		mlx_key_hook(map->mlx_win, key_hook, map);
		mlx_hook(map->mlx_win, 17, 0, close1, map);
		mlx_loop(map->mlx);
	}
	else
		perror("file does not accepted");
	return (0);
}
