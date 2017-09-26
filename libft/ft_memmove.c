/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:23:17 by rweiss            #+#    #+#             */
/*   Updated: 2016/06/20 15:12:11 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *s, size_t n)
{
	size_t	i;

	if (!((int *)dst > (int *)s && (int *)s + n > (int *)dst))
		ft_memcpy(dst, s, n);
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			*((char *)dst + i) = *((char *)s + i);
		}
	}
	return (dst);
}
