/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:16:52 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/13 17:22:28 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	size_t			i;
	unsigned char	*dup;

	dup = (unsigned char *)s;
	i = 0;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (dup[i] == ch)
			return (dup + i);
		i++;
	}
	return (NULL);
}
