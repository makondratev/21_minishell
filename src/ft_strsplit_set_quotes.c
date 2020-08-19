/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_set_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azomega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 20:16:04 by azomega           #+#    #+#             */
/*   Updated: 2020/08/16 20:45:02 by azomega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

static int		is_separator(char c, const char *charset)
{
	if (!c)
		return (1);
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

static size_t	countwords(const char *s, const char *charset, char quote)
{
	size_t	words;
	size_t	i;
	int		is_in_quote;

	i = 0;
	is_in_quote = -1;
	words = 0;
	while (s[i])
	{
		if (s[i] == quote)
			is_in_quote *= -1;
		if (is_in_quote < 0 && !is_separator(s[i], charset) &&
			is_separator(s[i + 1], charset))
			words++;
		i++;
	}
	return (words);
}

static void		getwords(char **arr, const char *s, const char *charset,
				char quote)
{
	int		i;
	size_t	j;
	size_t	len;
	int		is_in_quote;

	is_in_quote = -1;
	len = 0;
	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] == quote)
		{
			is_in_quote *= -1;
			len++;
		}
		else if (is_in_quote > 0 || !is_separator(s[i], charset))
			len++;
		else if (is_in_quote < 0 && len)
		{
			arr[j++] = ft_strsub(s, i - len, len);
			len = 0;
		}
	if (is_in_quote < 0 && len)
		arr[j] = ft_strsub(s, i - len, len);
}

char			**ft_strsplit_set_quotes(char const *s, const char *charset,
				char quote)
{
	size_t	wordcount;
	char	**sp;

	if (!s)
		return (NULL);
	wordcount = countwords(s, charset, quote);
	if (!(sp = (char**)malloc(sizeof(char*) * (wordcount + 1))))
		return (NULL);
	getwords(sp, s, charset, quote);
	sp[wordcount] = NULL;
	return (sp);
}
