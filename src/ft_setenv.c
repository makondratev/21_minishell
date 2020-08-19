/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:44:52 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 12:33:46 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "errors.h"

void	ft_setenv(const char **args, t_env *env)
{
	char	*key;
	char	*value;
	size_t	len;

	while (*(++args))
	{
		key = ft_strget_token(*args, '=', &len);
		if (len > 0)
		{
			if (ft_is_env_name_ok(key) && ft_strlen(*args) > len)
			{
				if (ft_strcmp(key, "PATH") == 0)
					env->path_need_update = 1;
				value = ft_strget_token(*args + len + 1, '\0', &len);
				ft_hm_insert(env->hm_env, key, value);
				free(value);
			}
			else
				ft_print_error(er_notvalid, "setenv", key);
		}
		free(key);
	}
	ft_update_env(env);
}
