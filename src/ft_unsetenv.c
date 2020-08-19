/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:45:03 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 12:34:50 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "errors.h"

void	ft_unsetenv(const char **args, t_env *env)
{
	while (*(++args))
	{
		if (ft_is_env_name_ok(*args))
		{
			if (ft_strcmp(*args, "PATH") == 0)
				env->path_need_update = 1;
			ft_hm_remove(env->hm_env, *args);
		}
		else
			ft_print_error(er_notvalid, "unsetenv", *args);
	}
	ft_update_env(env);
}
