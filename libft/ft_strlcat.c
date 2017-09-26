/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:26:06 by rweiss            #+#    #+#             */
/*   Updated: 2016/04/04 14:26:07 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < n)
		i++;
	while ((src[j]) && ((i + j + 1) < n))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != n)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
