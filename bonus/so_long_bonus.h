/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 02:42:50 by med-doba          #+#    #+#             */
/*   Updated: 2022/05/10 19:38:36 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct t_lay{
	int		height;
	char	**map;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
	int		i;
	int		j;
	int		l;
	int		move;
}t_lay;

char	*ft_newline_map(char *str, t_lay *mo, int x);
int		ft_extention(char *filemap);
void	ft_read(char *str, t_lay *map);
int		ft_rectangular(t_lay *mo);
int		ft_height(char *name);
int		ft_walls01(t_lay *mo, char c);
int		ft_walls02(t_lay *mo, char c);
int		ft_check(t_lay *mo, char c);
int		ft_externe(t_lay *mo);
int		ft_ifif(t_lay *mo);
void	ft_replace(t_lay *map);
void	ft_show(t_lay *map, int i, int j, char *path);
void	ft_move_up(t_lay *map, int i, int j);
void	ft_up(t_lay *map);
void	ft_move_down(t_lay *map, int i, int j);
void	ft_down(t_lay *map);
void	ft_move_rigth(t_lay *map, int i, int j);
void	ft_rigth(t_lay *map);
void	ft_move_left(t_lay *map, int i, int j);
void	ft_left(t_lay *map);
void	ft_close(t_lay *map);
void	ft_move(t_lay *map, char c);

#endif
