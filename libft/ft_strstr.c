/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:27:50 by rweiss            #+#    #+#             */
/*   Updated: 2016/06/22 15:09:16 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	char *a;
	char *b;

	b = to_find;
	if (*b == 0)
		return (str);
	while (*str != '\0')
	{
		if (*str != *b)
		{
			str++;
			continue ;
		}
		a = str;
		while (1)
		{
			if (*b == 0)
				return (str);
			if (*a++ != *b++)
				break ;
		}
		b = to_find;
		str++;
	}
	return ((char *)0);
}
