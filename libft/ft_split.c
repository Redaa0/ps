/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:53:48 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/13 17:26:48 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	substring_free(char **array, int count)
{
	while (count > 0)
	{
		free (array[count]);
		count--;
	}
	free(array);
}

static char	*subs_content(char const *s, char *substring, int len, int start)
{
	int	i;

	i = 0;
	while (i < len)
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}

static char	*subs_creation(char const *s, char c, int *index)
{
	char	*substring;
	int		len;
	int		start;

	substring = NULL;
	len = 0;
	while (s[*index] == c && s[*index])
		(*index)++;
	start = *index;
	while (s[*index] != c && s[*index])
	{
		(*index)++;
		len++;
	}
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	substring = subs_content(s, substring, len, start);
	return (substring);
}

static int	substring_count(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	i = 0;
	while (s[i])
	{
		flag = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			flag = 1;
		}
		if (flag == 1)
			count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		sub_count;
	int		i;
	int		index;

	if (!s)
		return (NULL);
	index = 0;
	i = 0;
	sub_count = substring_count(s, c);
	array = (char **)malloc(sizeof(char *) * (sub_count + 1));
	if (!array)
		return (NULL);
	array[sub_count] = NULL;
	while (i < sub_count)
	{
		array[i] = subs_creation(s, c, &index);
		if (array[i] == NULL)
		{
			substring_free(array, i);
			return (NULL);
		}
		i++;
	}
	return (array);
}
