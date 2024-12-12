/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:05:09 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/13 17:23:13 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destt;
	unsigned char	*dup;

	destt = (unsigned char *)dest;
	dup = (unsigned char *)src;
	if (!n)
		return (dest);
	if (destt > dup)
	{
		while (n > 0)
		{
			destt[n - 1] = dup[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(destt, dup, n);
	return (destt);
}
