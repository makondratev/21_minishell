/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:31:18 by azomega           #+#    #+#             */
/*   Updated: 2020/08/19 12:38:54 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"
#include <signal.h>

static void	handle_sigint(int sig)
{
	if (sig)
	{
		;
	}
	ft_putstr("\n$> ");
	g_is_need_promt = 0;
}

void		ft_print_list_as_pair(t_list *list)
{
	t_pair *pair;

	pair = (t_pair *)list->content;
	ft_putstr(pair->key);
	ft_putstr("=");
	ft_putendl(pair->value);
}

void		ft_print_map(t_hash_map *map)
{
	size_t i;

	i = 0;
	while (i < map->buckets_size)
		ft_lstiter(map->buckets[i++], ft_print_list_as_pair);
}

int			main(int argc, char **argv, char **env_args)
{
	char	*line;
	t_env	env;

	if (argc)
	{
		;
	}
	signal(SIGINT, handle_sigint);
	ft_init_env(&env, (const char **)env_args, (const char **)argv);
	ft_putstr("$> ");
	while (ft_mini_gnl(0, &line))
	{
		g_is_need_promt = 1;
		ft_run(line, &env);
		free(line);
		if (g_is_need_promt)
			ft_putstr("$> ");
	}
	ft_del_env(&env);
	ft_mini_gnl(-123, NULL);
	return (0);
}
