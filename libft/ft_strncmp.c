/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:02:59 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/13 17:29:04 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		flag;
	size_t	i;

	i = 0;
	flag = 0;
	if (n == 0)
		return (0);
	while ((((unsigned char *)s1)[i] || ((unsigned char *)s2)[i]) && i < n)
	{
		if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
		{
			flag = 1;
			break ;
		}
		else if (((unsigned char *)s1)[i] < ((unsigned char *)s2)[i])
		{
			flag = -1;
			break ;
		}
		i++;
	}
	return (flag);
}
