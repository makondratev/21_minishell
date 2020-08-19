/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:45:07 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 12:33:22 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	ft_update_env(t_env *env)
{
	if (env)
	{
		ft_free_matrix(env->arr_env);
		free(env->arr_env);
		env->arr_env = ft_hm_as_arr(env->hm_env);
		if (env->path_need_update)
		{
			ft_hm_del(env->hm_path);
			free(env->hm_path);
			env->hm_path = ft_get_path(ft_hm_get_value(env->hm_env, "PATH"));
			env->path_need_update = 0;
		}
	}
}
