/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:47:04 by azomega           #+#    #+#             */
/*   Updated: 2020/08/17 16:47:12 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include "env.h"

void	ft_del_env(t_env *env)
{
	ft_hm_del(env->hm_env);
	free(env->hm_env);
	ft_hm_del(env->hm_path);
	free(env->hm_path);
	ft_free_matrix(env->arr_env);
	free(env->arr_env);
	ft_free_matrix(env->arr_args);
	free(env->arr_args);
}
