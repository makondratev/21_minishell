/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_tilda.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:28:09 by azomega           #+#    #+#             */
/*   Updated: 2020/08/16 20:44:26 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_expand_tilda(char **line, t_env *env)
{
	char	*home;
	char	*result;

	if (!line)
		return ;
	while (*line)
	{
		if (**line == '~')
		{
			if (line[0][1] == '\0' || line[0][1] == '/')
			{
				if (!(home = ft_hm_get_value(env->hm_env, "HOME")))
					home = "";
				result = ft_strjoin(home, &line[0][1]);
				free(*line);
				*line = result;
			}
		}
		line++;
	}
}
