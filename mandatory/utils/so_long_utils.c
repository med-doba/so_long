/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:42 by med-doba          #+#    #+#             */
/*   Updated: 2022/05/10 20:59:08 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_extention(char *filemap)
{
	int	i;

	i = ft_strlen(filemap);
	if (filemap[i--] == '\0')
	{
		if (filemap[i--] == 'r')
		{
			if (filemap[i--] == 'e')
			{
				if (filemap[i--] == 'b')
				{
					if (filemap[i--] == '.')
					{
						if (filemap[i--] != 0)
						{
							return (1);
						}
					}
				}
			}
		}
	}
	return (0);
}

int	ft_height(char *name)
{
	int		height;
	char	*rtn;
	int		fd;

	height = 0;
	fd = open(name, O_RDONLY);
	rtn = get_next_line(fd, 1);
	if (rtn == NULL)
	{
		ft_printf("empty map\n");
		exit(1);
	}
	while (*rtn)
	{
		height++;
		free(rtn);
		rtn = get_next_line(fd, 1);
		if (rtn == NULL)
			break ;
	}
	close(fd);
	return (height);
}

int	ft_ifif(t_lay *mo)
{
	if (ft_rectangular(mo) == 0)
		return (printf("ERROR unRectangle map\n"), 0);
	else if (ft_walls01(mo, '1') == 0)
		return (printf("error line 1 empty\n"), 0);
	else if (ft_walls02(mo, '1') == 0)
		return (printf("error side line empty\n"), 0);
	else if (ft_check(mo, 'E') == 0)
		return (printf("no exit found\n"), 0);
	else if (ft_check(mo, 'C') == 0)
		return (printf("no collectable found\n"), 0);
	else if (ft_check(mo, 'P') != 1)
		return (printf("no player found or more detected\n"), 0);
	else if (ft_externe(mo) == 0)
		return (printf("Only P,E,C,0,1 allowed\n"), 0);
	else if (mo->l == mo->height)
		return (printf("The map must be rectangular\n"), 0);
	return (1);
}

void	ft_read(char *name, t_lay *mo)
{
	char	*rtn;
	int		i;
	int		fd;

	i = 0;
	fd = open(name, O_RDONLY);
	mo->height = ft_height(name);
	mo->map = (char **)malloc(sizeof(char *) * (mo->height) + 1);
	if (mo->map == NULL)
		exit(1);
	rtn = get_next_line(fd, 1);
	while (*rtn)
	{
		mo->map[i] = rtn;
		rtn = get_next_line(fd, 1);
		i++;
		if (rtn == NULL)
		{
			mo->map[i] = NULL;
			break ;
		}
	}
	close(fd);
	if (ft_ifif(mo) == 0)
		exit(1);
}
