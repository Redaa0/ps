/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:36:00 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/13 17:22:44 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_dup;
	unsigned char	*s2_dup;
	unsigned int	i;
	int				flag;

	i = 0;
	flag = 0;
	if (n == 0)
		return (0);
	s1_dup = (unsigned char *)s1;
	s2_dup = (unsigned char *)s2;
	while (i < n)
	{
		if (s1_dup[i] > s2_dup[i])
			return (1);
		else if (s1_dup[i] < s2_dup[i])
			return (-1);
		i++;
	}
	return (flag);
}
