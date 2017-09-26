/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 15:59:40 by rweiss            #+#    #+#             */
/*   Updated: 2017/04/26 17:11:04 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

# define BUFF 2000000000

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	char		*content;
	int			x_max;
	int			y_max;
	int			r;
	int			g;
	int			b;
	int			zoom;
	int			z_ch;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			**map;
}				t_window;

int			get_next_line(int const fd, char **line);
int			ft_init_mlx(t_window *w);
void		ft_put_points(t_window *w, int y, int x);
void		ft_draw_segm(t_window *w);
void		ft_draw(t_window *w);
int			loop_event(t_window *w);
void		ft_create_image(t_window *w, int i);
void		ft_fillmap(t_window *w, char **s, int *x, int y);
void		ft_exit(char *message);

#endif
