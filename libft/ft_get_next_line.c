/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 22:38:07 by eserebry          #+#    #+#             */
/*   Updated: 2017/09/29 01:11:18 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_check(char **buff, char **line)
{
	char	*tmp;

	tmp = ft_strchr(*buff, '\n');
	if (tmp)
	{
		*line = ft_strsub(*buff, 0, tmp - *buff);
		ft_memmove(*buff, tmp + 1, ft_strlen(tmp));
		tmp = NULL;
		return (1);
	}
	return (0);
}

static int	ft_read(int const fd, char **buff, char **line)
{
	char	*tmp;
	char	tmp2[BUFF_SIZE + 1];
	int		rd;

	while ((rd = read(fd, tmp2, BUFF_SIZE)))
	{
		if (rd == -1)
			return (-1);
		tmp2[rd] = '\0';
		tmp = NULL;
		if (*buff)
		{
			tmp = ft_strdup(*buff);
			ft_memdel((void **)buff);
			*buff = ft_strjoin(tmp, tmp2);
			ft_memdel((void **)&tmp);
		}
		else
			*buff = ft_strdup(tmp2);
		if (ft_check(buff, line))
			return (1);
	}
	return (0);
}

int			ft_get_next_line(const int fd, char **line)
{
	int				result;
	static	char	*buf[255] = {0};

	if (line == NULL || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (buf[fd] && ft_check(&buf[fd], line))
		return (1);
	result = ft_read(fd, &buf[fd], line);
	if (result != 0)
		return (result);
	if (buf[fd] == NULL || buf[fd][0] == '\0')
		return (0);
	*line = buf[fd];
	buf[fd] = NULL;
	return (1);
}
