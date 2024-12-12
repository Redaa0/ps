/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:51:47 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/13 17:29:11 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	ch;

	len = ft_strlen(s);
	ch = (char)c;
	while (len >= 0)
	{
		if (s[len] == ch)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
