/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:08:54 by azomega           #+#    #+#             */
/*   Updated: 2020/08/16 20:09:41 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"

typedef struct	s_env
{
	int			path_need_update;
	char		**arr_env;
	char		**arr_args;
	t_hash_map	*hm_env;
	t_hash_map	*hm_path;
}				t_env;

void			ft_init_env(t_env *env, const char	**environ,
				const char **argv);
void			ft_update_env(t_env *env);

#endif
