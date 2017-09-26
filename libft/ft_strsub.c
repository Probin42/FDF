/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:27:56 by rweiss            #+#    #+#             */
/*   Updated: 2016/06/22 14:49:48 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	dest = ft_memalloc(1);
	if (s && len > 0)
	{
		dest = (char *)malloc(sizeof(char) * (len + 1));
		if (dest)
		{
			i = 0;
			while (len--)
				dest[i++] = s[start++];
			dest[i] = '\0';
		}
	}
	return (dest);
}
