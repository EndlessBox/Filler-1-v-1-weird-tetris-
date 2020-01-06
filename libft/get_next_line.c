/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 14:52:59 by ybouladh          #+#    #+#             */
/*   Updated: 2019/07/19 14:53:04 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	white_space(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (++i);
		else
			i++;
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char	*s;
	char	buff[BUFF_SIZE + 1];
	int		i;
	char	*temp;
	int		rd;

	rd = 0;
	i = 0;
	temp = NULL;
	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	s = ft_strnew(1);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd] = '\0';
		temp = s;
		s = ft_strjoin(s, buff);
		ft_strdel(&temp);
		if (white_space(s))
			break ;
	}
	i = white_space(s);
	*line = ft_strsub(s, 0, i - 1);
	ft_strdel(&s);
	return (rd);
}
