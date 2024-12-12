/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoutaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:51:25 by rmoutaou          #+#    #+#             */
/*   Updated: 2023/11/13 17:28:27 by rmoutaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	total_len = s1_len + s2_len;
	string = malloc(sizeof(char) * (total_len + 1));
	if (!string)
		return (NULL);
	ft_memcpy(string, s1, s1_len);
	ft_memcpy(string + s1_len, s2, s2_len);
	string[s1_len + s2_len] = '\0';
	return (string);
}
