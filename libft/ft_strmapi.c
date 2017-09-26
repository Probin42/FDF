/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:26:26 by rweiss            #+#    #+#             */
/*   Updated: 2016/06/22 14:33:42 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	j;
	char			*tab;

	if (!s || !f)
		return (NULL);
	j = 0;
	tab = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!(tab = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	if (tab == NULL)
		return (NULL);
	while (s[j])
	{
		tab[j] = f(j, s[j]);
		j++;
	}
	tab[j] = '\0';
	return (tab);
}
