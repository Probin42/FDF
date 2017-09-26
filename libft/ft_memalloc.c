/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:22:16 by rweiss            #+#    #+#             */
/*   Updated: 2016/06/22 11:29:26 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*m;

	if (!(m = (void *)malloc(size)))
		return (NULL);
	if (m == NULL)
		return (NULL);
	ft_bzero(m, size);
	return (m);
}
