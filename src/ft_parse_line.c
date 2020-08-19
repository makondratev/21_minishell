/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:44:45 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 16:49:14 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static size_t	count_qoutes(const char *line, char quote)
{
	size_t	cnt;

	cnt = 0;
	while (*line)
		if (*line++ == quote)
			cnt++;
	return (cnt);
}

char			**ft_parse_line(const char *line)
{
	char	**args;
	char	sep[3];
	size_t	cnt;

	sep[0] = ' ';
	sep[1] = '\t';
	sep[2] = '\0';
	cnt = count_qoutes(line, '"');
	if (cnt % 2 != 0)
	{
		ft_putendl_fd("parse error", 2);
		return (NULL);
	}
	if (!cnt)
		args = ft_strsplit_set(line, sep);
	else
		args = ft_strsplit_set_quotes(line, sep, '"');
	return (args);
}
