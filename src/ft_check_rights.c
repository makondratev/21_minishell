/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_rights.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:25:39 by azomega           #+#    #+#             */
/*   Updated: 2020/08/16 20:44:15 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "errors.h"

static int	is_dir(const char *file_path)
{
	struct stat sb;

	if (stat(file_path, &sb) == 0)
		return (S_ISDIR(sb.st_mode));
	return (0);
}

int			ft_check_rights(const char *path)
{
	if (access(path, F_OK))
		return (er_noexec);
	else if (is_dir(path))
		return (er_isdir);
	else if (access(path, X_OK))
		return (er_acces);
	return (0);
}
