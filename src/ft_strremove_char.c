/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:44:58 by azomega           #+#    #+#             */
/*   Updated: 2020/08/16 20:44:59 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strremove_char(char *str, char c)
{
	size_t	i;
	size_t	delta;

	i = 0;
	delta = 0;
	while (str[i])
	{
		if (str[i] == c)
			delta++;
		else
			str[i - delta] = str[i];
		i++;
	}
	str[i - delta] = '\0';
}
