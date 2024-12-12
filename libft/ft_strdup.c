/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:45:28 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/13 17:27:55 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ss;
	char	*dup;

	i = 0;
	ss = (char *)s;
	dup = malloc(sizeof(char) * (ft_strlen(ss) + 1));
	if (!dup)
		return (NULL);
	while (ss[i])
	{
		dup[i] = ss[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
