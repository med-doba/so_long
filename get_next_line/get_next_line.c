/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:30:09 by med-doba          #+#    #+#             */
/*   Updated: 2022/04/24 15:37:51 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	endline(char *ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		if (ptr[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*sendline(char *ptr)
{
	char	*rtn;
	int		index;

	index = endline(ptr);
	if (index != -1)
	{
		rtn = malloc(sizeof(char) * (index + 2));
		if (!rtn)
			return (NULL);
		ftt_memcpy(rtn, ptr, index);
		rtn[index] = '\n';
		rtn[index + 1] = '\0';
	}
	else if (*ptr != '\0' && index == -1)
	{
		rtn = ftt_strdup(ptr);
		free(ptr);
	}
	else
		return (free(ptr), NULL);
	return (rtn);
}

char	*update(char *ptr)
{
	int		i;
	char	*rtn;

	rtn = NULL;
	i = endline(ptr);
	if (i != -1)
	{
		rtn = ftt_strdup(ptr + i + 1);
		free(ptr);
		ptr = rtn;
	}
	else if (i == -1 && *ptr != '\0')
		return (NULL);
	return (rtn);
}

char	*get_next_line(int fd, int BUFFER_SIZE)
{
	char		*rtn;
	char		*tab;
	static char	*ptr = NULL;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tab = malloc(BUFFER_SIZE + 1);
	if (!tab)
		return (free(tab), NULL);
	n = 1;
	while (endline(ptr) == -1 && n != 0)
	{
		n = read(fd, tab, BUFFER_SIZE);
		if (n == -1)
			return (free(ptr), free(tab), NULL);
		tab[n] = '\0';
		ptr = ftt_strjoin(ptr, tab);
	}
	free(tab);
	rtn = sendline(ptr);
	ptr = update(ptr);
	return (rtn);
}
