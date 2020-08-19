/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hm_as_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:44:33 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 12:31:44 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static size_t	ft_lstcnt(const t_list *lst)
{
	size_t	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

static size_t	ft_hm_cnt(const t_hash_map *map)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (i < map->buckets_size)
		count += ft_lstcnt(map->buckets[i++]);
	return (count);
}

static char		*concat_env(const void *pair)
{
	char	*left;
	char	*full;

	left = ft_strjoin(((t_pair *)pair)->key, "=");
	full = ft_strjoin(left, ((t_pair *)pair)->value);
	free(left);
	return (full);
}

char			**ft_hm_as_arr(const t_hash_map *map)
{
	char	**arr;
	size_t	len;
	size_t	i;
	t_list	*lst;

	i = 0;
	len = ft_hm_cnt(map);
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	arr[len] = NULL;
	while (len && i < map->buckets_size)
	{
		lst = map->buckets[i++];
		while (lst)
		{
			arr[--len] = concat_env(lst->content);
			lst = lst->next;
		}
	}
	return (arr);
}
