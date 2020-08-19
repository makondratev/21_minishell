/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:28:27 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 13:18:14 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_get_positional_arg(char c, t_env *env)
{
	size_t		i;

	i = c - '0';
	if (ft_cnt_matrix_size((const char **)env->arr_args) > i)
		return (env->arr_args[i]);
	return ("");
}

static char	*get_name(char *line)
{
	size_t		i;
	char		*name;

	i = 0;
	while (ft_isalnum(line[i]) || line[i] == '_')
		i++;
	name = ft_strsub(line, 0, i);
	return (name);
}

static void	concat_with_value(char **line, int *index, char *rhs, t_env *env)
{
	char	*value;
	char	*lhs;
	char	*result;
	size_t	len;

	result = get_name(rhs + 1);
	len = ft_strlen(result);
	value = ft_hm_get_value(env->hm_env, result);
	free(result);
	lhs = ft_strsub(*line, 0, *index);
	if (value)
	{
		*index += ft_strlen(value);
		result = ft_strjoin3(lhs, value, rhs + len + 1);
	}
	else
		result = ft_strjoin(lhs, rhs + len + 1);
	free(lhs);
	free(*line);
	*line = result;
}

static void	expand_dollar(char **line, int *index, t_env *env)
{
	char	*lhs;
	char	*value;
	char	*rhs;
	char	*result;

	rhs = *line + *index;
	if (!ft_isalnum(rhs[1]) && rhs[1] != '_')
		(*index)++;
	else if (ft_isdigit(rhs[1]))
	{
		lhs = ft_strsub(*line, 0, *index);
		value = ft_get_positional_arg(rhs[1], env);
		*index += ft_strlen(value);
		result = ft_strjoin3(lhs, value, &rhs[2]);
		free(*line);
		free(lhs);
		*line = result;
	}
	else
		concat_with_value(line, index, rhs, env);
}

void		ft_expand_dollar(char **line, t_env *env)
{
	char	*dollar;
	int		index;

	if (!line)
		return ;
	while (*line)
	{
		index = 0;
		while ((dollar = ft_strchr(*line + index, '$')))
		{
			index = dollar - *line;
			expand_dollar(line, &index, env);
		}
		line++;
	}
}
