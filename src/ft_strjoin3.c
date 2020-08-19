/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:31:42 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 13:31:44 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	char	*result;
	char	*lhs;

	if (!(lhs = ft_strjoin(s1, s2)))
		return (NULL);
	result = ft_strjoin(lhs, s3);
	free(lhs);
	return (result);
}
