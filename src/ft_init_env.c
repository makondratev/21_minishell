/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:44:36 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 12:24:00 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	ft_init_env(t_env *env, const char **environ, const char **argv)
{
	char	*lvl;

	env->hm_env = ft_get_env(environ);
	if (!(lvl = ft_hm_get_value(env->hm_env, "SHLVL")))
		ft_hm_insert(env->hm_env, "SHLVL", "1");
	else
	{
		lvl = ft_itoa(ft_atoi(lvl) + 1);
		ft_hm_insert(env->hm_env, "SHLVL", lvl);
		free(lvl);
	}
	env->arr_env = ft_hm_as_arr(env->hm_env);
	env->arr_args = ft_copy_str_matrix(argv);
	env->hm_path = ft_get_path(ft_hm_get_value(env->hm_env, "PATH"));
	env->path_need_update = 0;
}
