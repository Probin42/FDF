/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:27:22 by rweiss            #+#    #+#             */
/*   Updated: 2016/04/04 14:27:23 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *a, const char *b, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (a[i] != '\0' && i < n)
	{
		j = 0;
		while (b[j] != '\0' && a[i + j] == b[j] && i + j < n)
			j++;
		if (b[j] == '\0')
			return ((char *)a + i);
		i++;
	}
	return (NULL);
}
