/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:21:26 by rweiss            #+#    #+#             */
/*   Updated: 2017/05/30 13:09:48 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_put_points(t_window *w, int y, int x) // dessine pixel par pixel selon la taille de ta fenetre les points.
{
	if ((x > 0 && y > 0) && (x <= 800 && y <= 500))
	{
		w->content[(x * 4) + (y * 800 * 4)] = w->r;
		w->content[(x * 4) + (y * 800 * 4) + 1] = w->g;
		w->content[(x * 4) + (y * 800 * 4) + 2] = w->b;
	}
}

void		ft_draw_segm(t_window *w) // fonction qui dessine les segments entre les points, les relie
{
	double	tx;
	double	ty;
	double	x;
	double	y;
	double	tmp;

	x = w->x1;
	y = w->y1;
	tx = w->x2 - w->x1;
	ty = w->y2 - w->y1;
	tmp = sqrt((tx * tx) + (ty * ty));
	tx = tx / tmp;
	ty = ty / tmp;
	while (tmp >= 0)
	{
		ft_put_points(w, y, x);
		x = tx + x;
		y = ty + y;
		tmp--;
	}
}

void		ft_options(t_window *w, int x, int y, int i) // fonction qui gere les options : couleur, zoom, profondeur. Replace les points dans l'espace suite au changement de leurs valeurs.
{
	int		tx;
	int		ty;

	tx = x - w->x_max / 2;
	ty = y - w->y_max / 2;
	w->x1 = 0.40 * (tx - ty) * w->zoom;
	w->y1 = 0.20 * (tx + ty) * w->zoom;
	w->y1 -= w->map[y][x] * w->z_ch;
	if (i)
	{
		w->x2 = 0.40 * ((tx + 1) - ty) * w->zoom;
		w->y2 = 0.20 * ((tx + 1) + ty) * w->zoom;
		w->y2 -= w->map[y][x + 1] * w->z_ch;
	}
	else
	{
		w->x2 = 0.40 * (tx - (ty + 1)) * w->zoom;
		w->y2 = 0.20 * (tx + (ty + 1)) * w->zoom;
		w->y2 -= w->map[y + 1][x] * w->z_ch;
	}
	w->x1 += 800 / 2;
	w->x2 += 800 / 2;
	w->y1 += 500 / 2;
	w->y2 += 500 / 2;
}

void		ft_condition(t_window *w, int x, int y) // gestion d'erreur et des conditions dans lesquelles on va pouvoir dessiner, zoomer et compagnie. 
{
	x = 0;
	y = 0;
	while (y != w->y_max)
	{
		while (x != w->x_max)
		{
			w->x1 = x;
			w->y1 = y;
			if (x + 1 < w->x_max && w->map[y][x] != \
					BUFF && w->map[y][x + 1] != BUFF)
			{
				ft_options(w, x, y, 1); //attention au 1
				ft_draw_segm(w);
			}
			if (y + 1 < w->y_max && w->map[y][x] != \
					BUFF && w->map[y + 1][x] != BUFF)
			{
				ft_options(w, x, y, 0); //attention au 0
				ft_draw_segm(w);
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void		ft_draw(t_window *w) // fonction qui dessine
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_create_image(w, 1);
	ft_condition(w, x, y);
	ft_create_image(w, 2);
}
