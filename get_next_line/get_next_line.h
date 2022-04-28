/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: med-doba <med-doba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:30:43 by med-doba          #+#    #+#             */
/*   Updated: 2022/04/24 15:38:20 by med-doba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"

char	*get_next_line(int fd, int BUFFER_SIZE);
int		ftt_strlen(const char *ptr);
char	*ftt_strjoin(char *s1, char *s2);
char	*ftt_strdup(const char *s1);
void	*ftt_memcpy(void *dst, const void *src, size_t n);
int		endline(char *ptr);
char	*sendline(char *ptr);
char	*update(char *ptr);
#endif
