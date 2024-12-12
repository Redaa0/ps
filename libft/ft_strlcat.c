/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:01:59 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/13 17:28:35 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;
	size_t	len_dup;

	i = 0;
	src_len = ft_strlen(src);
	if (!dst && size == 0)
		return (src_len);
	dest_len = ft_strlen(dst);
	len_dup = dest_len;
	if (size <= dest_len)
		return (size + src_len);
	while (src[i] && len_dup + 1 < size)
	{
		dst[len_dup] = src[i];
		len_dup++;
		i++;
	}
	dst[len_dup] = '\0';
	return (src_len + dest_len);
}
