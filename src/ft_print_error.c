/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:44:48 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 12:28:26 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "libft.h"

static const char	*get_err_msg(enum e_errors er)
{
	static const char	*er_msg[9] = {
		"Permission denied",
		"No such file or directory",
		"command not found",
		"is a directory",
		"too many arguments",
		"numeric argument required",
		"not a valid identifier",
		"HOME not set",
		"OLDPWD not set"
	};

	return (er_msg[er - 1]);
}

void				ft_print_error(enum e_errors error, const char *exec,
					const char *arg)
{
	ft_putstr_fd(exec, 2);
	ft_putstr_fd(": ", 2);
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(get_err_msg(error), 2);
}
