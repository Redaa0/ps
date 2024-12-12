/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:51:29 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/13 16:48:40 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
