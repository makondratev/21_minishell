/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:23:35 by azomega           #+#    #+#             */
/*   Updated: 2020/08/16 20:45:37 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	ft_echo(const char **args)
{
	const char	**arg;

	arg = &args[1];
	while (*arg)
	{
		if (*arg != args[1])
			ft_putstr(" ");
		ft_putstr(*arg++);
	}
	ft_putendl("");
}
