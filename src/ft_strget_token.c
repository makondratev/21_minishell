/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strget_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:44:55 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 12:25:11 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strget_token(char const *s, char delim, size_t *length)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i] && s[i] != delim)
			i++;
	*length = i;
	return (ft_strsub(s, 0, i));
}
