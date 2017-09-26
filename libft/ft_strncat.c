/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:26:32 by rweiss            #+#    #+#             */
/*   Updated: 2016/04/04 14:26:34 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t size;
	size_t i;

	size = 0;
	i = ft_strlen(dest);
	while (size < nb && src[size])
	{
		dest[i + size] = src[size];
		size++;
	}
	dest[i + size] = '\0';
	return (dest);
}
