/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 02:04:46 by rmoutaou          #+#    #+#             */
/*   Updated: 2024/05/06 23:18:20 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

char	*my_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	if (!s)
		return (0);
	ch = (char)c;
	while (s[i] != ch)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

void	*my_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*srcc;
	unsigned char	*destt;

	i = 0;
	if (!dest && !src)
		return (NULL);
	srcc = (unsigned char *)src;
	destt = (unsigned char *)dest;
	while (i < n)
	{
		destt[i] = srcc[i];
		i++;
	}
	return (destt);
}

char	*my_strjoin(char *s1, char *s2)
{
	char	*string;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s1_len = my_strlen(s1);
	s2_len = my_strlen(s2);
	total_len = s1_len + s2_len;
	string = malloc(sizeof(char) * (total_len + 1));
	if (!string)
		return (NULL);
	my_memcpy(string, s1, s1_len);
	my_memcpy(string + s1_len, s2, s2_len);
	string[s1_len + s2_len] = '\0';
	free(s1);
	return (string);
}