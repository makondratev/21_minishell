/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:44:21 by azomega           #+#    #+#             */
/*   Updated: 2020/08/16 20:45:55 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"
#include "errors.h"

static int	is_numeric(const char *nb)
{
	while (*nb)
		if (!ft_isdigit(*nb++))
			return (0);
	return (1);
}

void		ft_exit(const char **args)
{
	ft_mini_gnl(-123, NULL);
	if (!args[1])
		exit(0);
	else if (!is_numeric(args[1]))
	{
		ft_print_error(er_numargreq, args[0], args[1]);
		exit(255);
	}
	else if (!args[2])
		exit(ft_atoi(args[1]));
	else
		ft_print_error(er_tmargs, args[0], NULL);
}
