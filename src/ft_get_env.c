/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:44:27 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 12:23:25 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash_map	*ft_get_env(const char **env)
{
	t_hash_map	*map;
	char		**key_value;

	map = (t_hash_map *)malloc(sizeof(t_hash_map));
	ft_hm_init(map, 100);
	if (env)
		while (*env)
		{
			key_value = ft_strsplit_set(*env, "=");
			if (!key_value)
				return (NULL);
			if (key_value[0] && key_value[1])
				ft_hm_insert(map, key_value[0], key_value[1]);
			else
				ft_hm_insert(map, key_value[0], "");
			free(key_value[0]);
			free(key_value[1]);
			free(key_value);
			env++;
		}
	return (map);
}
