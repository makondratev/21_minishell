/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:44:02 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 12:32:46 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "errors.h"
#include <unistd.h>

static void	swap_dirs(t_env *env)
{
	char	*old_pwd;
	char	*pwd;
	char	*tmp;

	if (!(old_pwd = ft_hm_get_value(env->hm_env, "OLDPWD"))
		|| !ft_strlen(old_pwd))
		return (ft_print_error(er_nooldpwd, "bash", "cd"));
	chdir(old_pwd);
	if (!(pwd = ft_hm_get_value(env->hm_env, "PWD")))
	{
		ft_hm_insert(env->hm_env, "PWD", old_pwd);
		ft_hm_insert(env->hm_env, "OLDPWD", "");
	}
	else
	{
		tmp = ft_strdup(pwd);
		ft_hm_insert(env->hm_env, "PWD", old_pwd);
		ft_hm_insert(env->hm_env, "OLDPWD", tmp);
		free(tmp);
	}
	ft_update_env(env);
}

static void	change_dir(const char *new_dir, t_env *env)
{
	char	cur_dir[4096];
	int		error;

	getcwd(cur_dir, 4096);
	error = chdir(new_dir);
	if (!error)
	{
		ft_hm_insert(env->hm_env, "OLDPWD", cur_dir);
		getcwd(cur_dir, 4096);
		ft_hm_insert(env->hm_env, "PWD", cur_dir);
		ft_update_env(env);
	}
	else
		ft_print_error(er_noent, "cd", new_dir);
}

void		ft_cd(const char **args, t_env *env)
{
	char	*new_dir;

	if (!*(args + 1))
	{
		if (!(new_dir = ft_hm_get_value(env->hm_env, "HOME")))
			return (ft_print_error(er_nohome, "minishell", "cd"));
	}
	else
		new_dir = (char *)args[1];
	if (ft_strlen(new_dir) == 0)
		return ;
	if (ft_strcmp(new_dir, "-") == 0)
		swap_dirs(env);
	else
		change_dir(new_dir, env);
}
