/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:27:36 by rweiss            #+#    #+#             */
/*   Updated: 2016/04/04 14:27:38 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		j;

	j = ft_strlen(s);
	if (c == 0)
		return ((char *)s + j);
	while (--j >= 0)
	{
		if (s[j] == c)
			return ((char *)s + j);
	}
	return (NULL);
}
