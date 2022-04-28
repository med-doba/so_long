/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 02:42:02 by med-doba          #+#    #+#             */
/*   Updated: 2022/04/27 22:58:05 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}

int	main(int ac, char *av[])
{
	t_lay	*map;
	int		fd;

	map = (t_lay *)malloc(sizeof(t_lay));
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
	{
		perror("warning,only the first one will be used");
		exit (0);
	}
	if (ac == 2)
	{
		if (ft_extention(av[1]) == 1)
		{
			ft_read(av[1], map, fd);
			map->mlx = mlx_init();
			map->mlx_win = mlx_new_window(map->mlx, 600, 300, "Hello world!");
			// mlx_key_hook(map->mlx_win, key_hook, &*map);
			ft_replace(map);
			mlx_loop(map->mlx);
		}
		else
			perror("file does not accepted");
		
	}
	return (0);
}
