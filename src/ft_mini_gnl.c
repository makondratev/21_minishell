/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:15:44 by azomega           #+#    #+#             */
/*   Updated: 2020/08/16 20:44:44 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static int		ft_read_one_line(char **stat_buf, char **line, const int fd)
{
	char	buf[BUF_SIZE + 1];
	size_t	rd;
	char	*tmp;
	char	*ret;

	rd = 1;
	while (rd > 0)
	{
		if ((ret = ft_strchr(*stat_buf, '\n')))
			*ret++ = '\0';
		if (!(tmp = ft_strjoin(*line, *stat_buf)))
			return (-1);
		free(*line);
		*line = tmp;
		if (ret && !(ret = ft_strdup(ret)))
			return (-1);
		free(*stat_buf);
		if ((*stat_buf = ret))
			return (1);
		rd = read(fd, buf, BUF_SIZE);
		if (!(*stat_buf = ft_strsub(buf, 0, rd)))
			return (-1);
	}
	return (0);
}

int				ft_mini_gnl(const int fd, char **line)
{
	static char		*stat_buf = 0;
	int				retval;

	if (stat_buf && fd == -123)
		ft_strdel(&stat_buf);
	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	if (!(*line = ft_strnew(0)))
		return (-1);
	if (!stat_buf && !(stat_buf = ft_strnew(0)))
		return (-1);
	if ((retval = ft_read_one_line(&stat_buf, line, fd)) == 0)
	{
		if (ft_strlen(*line) > 0)
			return (1);
		ft_strdel(&stat_buf);
	}
	return (retval);
}
