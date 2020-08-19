/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:44:31 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 12:43:37 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <sys/types.h>
#include <dirent.h>

static void	insert_with_join(t_hash_map *map, const char *item,
			const char *path)
{
	char	*full;
	char	*path_l;

	path_l = ft_strjoin(path, "/");
	full = ft_strjoin(path_l, item);
	ft_hm_insert(map, item, full);
	free(path_l);
	free(full);
}

static void	get_path(t_hash_map *map, const char *path)
{
	char			**pathes;
	char			**begin;
	DIR				*dirp;
	struct dirent	*dire;

	pathes = ft_strsplit_set(path, ":");
	begin = pathes;
	if (pathes)
	{
		while (*pathes)
		{
			if ((dirp = opendir(*pathes)))
			{
				while ((dire = readdir(dirp)))
					if (dire->d_type == DT_REG)
						insert_with_join(map, dire->d_name, *pathes);
				closedir(dirp);
			}
			pathes++;
		}
		ft_free_matrix(begin);
		free(begin);
	}
}

t_hash_map	*ft_get_path(const char *path)
{
	t_hash_map	*path_map;

	path_map = (t_hash_map *)malloc(sizeof(t_hash_map));
	ft_hm_init(path_map, 100000);
	get_path(path_map, path);
	return (path_map);
}
