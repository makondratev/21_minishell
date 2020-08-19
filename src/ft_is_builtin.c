/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:58:23 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 12:58:36 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_is_builtin(const char *exec)
{
	if (!ft_strcmp("setenv", exec) ||
			!ft_strcmp("unsetenv", exec) ||
			!ft_strcmp("env", exec) ||
			!ft_strcmp("exit", exec) ||
			!ft_strcmp("cd", exec) ||
			!ft_strcmp("echo", exec))
		return (1);
	return (0);
}
