/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:26:56 by rweiss            #+#    #+#             */
/*   Updated: 2016/04/04 14:26:57 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(n + 1);
	if (str)
	{
		ft_memcpy(str, s, n);
		str[n] = 0;
	}
	return (str);
}
