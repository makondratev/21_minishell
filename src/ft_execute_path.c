/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:46:41 by azomega           #+#    #+#             */
/*   Updated: 2020/08/19 12:42:54 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft.h"
#include "minishell.h"
#include "errors.h"

void	ft_execute_path(const char *path, const char **args, char **env)
{
	pid_t	pid;
	pid_t	w_pid;
	int		wait_status;
	int		err_code;

	if ((err_code = ft_check_rights(path)))
		ft_print_error(err_code, "minishell", args[0]);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			err_code = execve(path, (char *const *)args, env);
			exit(0);
		}
		else if (pid == -1)
			ft_putendl_fd("Cant fork process\n", 2);
		else
		{
			w_pid = wait(&wait_status);
			if (w_pid)
			{
				;
			}

		}
	}
}
