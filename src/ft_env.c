/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:14:26 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 16:48:49 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static void	null_env(t_env *env)
{
	env->arr_args = NULL;
	env->arr_env = NULL;
	env->hm_env = NULL;
	env->hm_path = NULL;
}

void		ft_env(const char **args, t_env *env)
{
	t_env	loc_env;
	char	*eql;

	null_env(&loc_env);
	if (!(*(++args)))
		return (ft_print_str_matrix((const char **)env->arr_env, ""));
	else if (!ft_strcmp(*args, "-") || !ft_strcmp(*args, "-i"))
		loc_env.hm_env = ft_get_env(NULL);
	else
		loc_env.hm_env = ft_get_env((const char **)env->arr_env);
	while (*(++args) && (eql = ft_strchr(*args, '=')))
	{
		*(eql++) = '\0';
		ft_hm_insert(loc_env.hm_env, *args, eql);
	}
	loc_env.arr_env = ft_hm_as_arr(loc_env.hm_env);
	if (!*args)
		ft_print_str_matrix((const char **)loc_env.arr_env, "'");
	else
	{
		loc_env.hm_path = ft_get_path(ft_hm_get_value(env->hm_env, "PATH"));
		ft_execute(args, &loc_env);
	}
	ft_del_env(&loc_env);
}
