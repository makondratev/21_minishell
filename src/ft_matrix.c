/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:39:38 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 16:47:38 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_free_matrix(char **m)
{
	if (m)
		while (*m)
			free(*m++);
}

size_t			ft_cnt_matrix_size(const char **m)
{
	size_t	len;

	len = 0;
	if (!m)
		return (0);
	while (*m++)
		len++;
	return (len);
}

void			ft_print_str_matrix(const char **args, char *sep)
{
	if (args)
	{
		while (*args)
		{
			ft_putstr(sep);
			ft_putstr(*args);
			ft_putendl(sep);
			args++;
		}
	}
}

static size_t	count_matrix_len(const char **m)
{
	size_t	len;

	len = 0;
	while (*m++)
		len++;
	return (len);
}

char			**ft_copy_str_matrix(const char **matrix)
{
	char	**lines;
	char	**iter;

	if (!matrix)
		return (NULL);
	lines = (char **)malloc(sizeof(char *) * (count_matrix_len(matrix) + 1));
	iter = lines;
	while (*matrix)
		*iter++ = ft_strdup(*matrix++);
	*iter = NULL;
	return (lines);
}
