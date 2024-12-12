/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:56:45 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/15 21:48:43 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	mem;
	size_t	src_len;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	mem = 0;
	if (start < src_len)
		mem = src_len - start;
	if (mem > len)
		mem = len;
	sub = malloc(sizeof(char) * (mem + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, mem + 1);
	return (sub);
}
