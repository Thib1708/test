/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 14:13:55 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/16 14:51:17 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_count(const char *str, char charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (charset == str[i] && str[i])
			i++;
		while (charset != str[i] && str[i])
		{
			i++;
			if (charset == str[i] || !str[i])
				count++;
		}
	}
	return (count);
}

static void	free_all_strings(char ***strings)
{
	while (*strings)
	{
		free(*strings++);
	}
	free(strings);
	*strings = NULL;
}

static void	ft_strings(const char *str, char charset, char **strings)
{
	int		index;
	int		save;
	int		i;

	i = 0;
	index = 0;
	while (str[i])
	{
		while (charset == str[i] && str[i])
			i++;
		save = i;
		while (charset != str[i] && str[i])
			i++;
		if (i != save)
		{
			strings[index] = malloc(sizeof(char) * (i - save + 2));
			if (!strings[index])
			{
				free_all_strings(&strings);
				return ;
			}
			ft_strlcpy(strings[index++], str + save, i - save + 1);
		}
	}
	strings[index] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**strings;

	if (!s)
		return (NULL);
	strings = malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!strings)
		return (NULL);
	ft_strings(s, c, strings);
	return (strings);
}
