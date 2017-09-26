/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <rweiss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 14:20:06 by rweiss            #+#    #+#             */
/*   Updated: 2016/06/22 13:48:20 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*r;
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !f)
		return (NULL);
	tmp2 = f(lst);
	if ((r = ft_lstnew(tmp2->content, tmp2->content_size)))
	{
		tmp = r;
		lst = lst->next;
		while (lst)
		{
			tmp2 = f(lst);
			if (!(tmp->next = ft_lstnew(tmp2->content, tmp2->content_size)))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (r);
}
