/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:02:07 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/13 20:33:36 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dup;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char) c;
	dup = (unsigned char *)s;
	while (i < n)
	{
		dup[i] = ch;
		i++;
	}
	return (dup);
}
