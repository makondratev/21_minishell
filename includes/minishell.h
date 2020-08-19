/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:09:59 by azomega           #+#    #+#             */
/*   Updated: 2020/08/16 20:13:09 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define BUF_SIZE 256
# include "env.h"

int			g_is_need_promt;

char		**ft_read_args(const char *line);
t_hash_map	*ft_get_env(const char **env);
void		ft_print_str_matrix(const char **args, char *sep);
char		**ft_copy_str_matrix(const char **matrix);
t_hash_map	*ft_get_path(const char *path);

int			ft_check_rights(const char *path);
void		ft_execute_path(const char *path, const char **args, char **env);
void		ft_execute(const char **args, t_env *env);
int			ft_run(const char *line, t_env *env);
void		ft_free_matrix(char **m);
size_t		ft_cnt_matrix_size(const char **m);
void		ft_exit(const char **args);
int			ft_mini_gnl(const int fd, char **line);
void		ft_env(const char **args, t_env *env);
void		ft_echo(const char **args);
void		ft_setenv(const char **args, t_env *env);
void		ft_unsetenv(const char **args, t_env *env);
int			ft_is_env_name_ok(const char *name);
char		*ft_strget_token(char const *s, char delim, size_t	*length);
char		**ft_parse_line(const char *line);
char		**ft_strsplit_set_quotes(char const *s, const char *charset,
			char quote);
void		ft_strremove_char(char *str, char c);
void		ft_expand_tilda(char **line, t_env *env);
void		ft_expand_dollar(char **line, t_env *env);
void		ft_cd(const char **args, t_env *env);
char		**ft_hm_as_arr(const t_hash_map *map);
int			ft_is_builtin(const char *exec);
char		*ft_strjoin3(char *s1, char *s2, char *s3);
void		ft_del_env(t_env *env);

#endif
