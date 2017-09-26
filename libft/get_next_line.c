/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:06:33 by rweiss            #+#    #+#             */
/*   Updated: 2017/03/27 12:34:16 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include "../libft/libft.h"

static char			*freeconcat(char *str, char *buf, int i)
{
	char			*c;

	c = str;
	str = ft_strnjoin(str, buf, i);
	free(c);
	return (str);
}

static t_list		*find_fd(t_list **begin, int fd)
{
	t_list			*tmp;

	tmp = *begin;
	if (tmp != '\0')
	{
		while (tmp != '\0')
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(begin, tmp);
	return (tmp);
}

int					get_next_line(const int fd, char **line)
{
	int				i;
	t_list			*begin;
	char			*c;
	static t_list	*list = NULL;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	begin = list;
	list = find_fd(&begin, fd);
	while (!ft_strchr(list->content, '\n') && (i = read(fd, buf, BUFF_SIZE)))
		list->content = freeconcat(list->content, buf, i);
	i = 0;
	while (((char *)list->content)[i] && ((char *)list->content)[i] != '\n')
		i++;
	*line = ft_strndup(list->content, i);
	if (((char *)list->content)[i] == '\n')
		i++;
	c = list->content;
	list->content = ft_strdup(list->content + i);
	free(c);
	list = begin;
	return (i ? 1 : 0);
}
