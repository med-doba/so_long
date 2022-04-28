/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:03:42 by med-doba          #+#    #+#             */
/*   Updated: 2022/04/27 22:26:19 by med-doba         ###   ########.fr       */
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

int	ft_height(int fd)
{
	int		height;
	char	*rtn;

	height = 0;
	rtn = get_next_line(fd, 1);
	while (*rtn)
	{
		height++;
		rtn = get_next_line(fd, 1);
		if (rtn == NULL)
			break ;
	}
	close(fd);
	return (height);
}

char	*ft_newline_map(char *str, t_lay *mo, int i)
{
	int		l;
	char	*rtn;

	l = ft_strlen(str) - 1;
	if (i < mo->height - 1)
		rtn = ft_substr(str, 0, l);
	else
		rtn = str;
	return (rtn);
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
	return (1);
}

void	ft_read(char *name, t_lay *mo, int fd)
{
	char	*rtn;
	int		i;

	i = 0;
	mo->height = ft_height(fd);
	fd = open(name, O_RDONLY);
	mo->map = (char **)malloc(sizeof(char *) * (mo->height) + 1);
	rtn = get_next_line(fd, 1);
	while (*rtn)
	{
		mo->map[i] = ft_newline_map(rtn, mo, i);
		rtn = get_next_line(fd, 1);
		if (rtn == NULL)
			break ;
		i++;
	}
	i = 0;
	if (ft_ifif(mo) == 1)
	{
		while (i < mo->height)
			ft_printf("%s\n", mo->map[i++]);
		close(fd);
	}
	else
		exit(0);
}
