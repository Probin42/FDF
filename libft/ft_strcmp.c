/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:24:57 by rweiss            #+#    #+#             */
/*   Updated: 2016/04/04 14:24:58 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	j;

	j = 0;
	while (s1[j] == s2[j] && s1[j] != '\0')
		j++;
	return ((unsigned char)s1[j] - (unsigned char)s2[j]);
}
