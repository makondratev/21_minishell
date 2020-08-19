/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:24:05 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 12:51:45 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "errors.h"

static int		is_path(const char *path)
{
	return (path && (!ft_strncmp("/", path, 1) ||
				!ft_strncmp("./", path, 2) || !ft_strncmp("../", path, 3)));
}

void			ft_run_builtin(const char **args, t_env *env)
{
	if (!ft_strcmp(args[0], "exit"))
		ft_exit(args);
	else if (!ft_strcmp(args[0], "env"))
		ft_env(args, env);
	else if (!ft_strcmp(args[0], "setenv"))
		ft_setenv(args, env);
	else if (!ft_strcmp(args[0], "unsetenv"))
		ft_unsetenv(args, env);
	else if (!ft_strcmp(args[0], "echo"))
		ft_echo(args);
	else if (!ft_strcmp(args[0], "cd"))
		ft_cd(args, env);
}

void			ft_execute(const char **args, t_env *env)
{
	char	*exec_path;

	if (is_path(args[0]))
		ft_execute_path(args[0], args, env->arr_env);
	else if (ft_is_builtin(args[0]))
		ft_run_builtin(args, env);
	else if ((exec_path = ft_hm_get_value(env->hm_path, args[0])))
		ft_execute_path(exec_path, args, env->arr_env);
	else
		ft_print_error(er_noexec, "minishell", args[0]);
}

static void		ft_remove_char(char **m, char quote)
{
	if (m)
		while (*m)
			ft_strremove_char(*m++, quote);
}

int				ft_run(const char *line, t_env *env)
{
	char	**args;

	args = ft_parse_line(line);
	ft_expand_tilda(args, env);
	ft_expand_dollar(args, env);
	ft_remove_char(args, '"');
	if (ft_cnt_matrix_size((const char **)args))
		ft_execute((const char **)args, env);
	ft_free_matrix(args);
	free(args);
	return (0);
}
