/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:24:44 by rweiss            #+#    #+#             */
/*   Updated: 2016/04/04 14:24:45 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr(const char *s, int c)
{
	unsigned int	j;

	j = 0;
	while (s[j] != '\0')
	{
		if (s[j] == c)
			return ((char *)s + j);
		j++;
	}
	if (!c && s[j] == '\0')
		return ((char *)s + j);
	return (NULL);
}
