/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxfuncts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:21:15 by rweiss            #+#    #+#             */
/*   Updated: 2017/05/30 13:06:17 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_init_mlx(t_window *w) // initialise les valeurs ainsi que la fenetre
{
	if (!(w->mlx = mlx_init()))
		return (1);
	w->win = mlx_new_window(w->mlx, 800, 500, "FDF@RW");
	w->r = 100;
	w->g = 100;
	w->b = 100;
	w->zoom = 30;
	w->z_ch = 1;
	return (0);
}

void		ft_create_image(t_window *w, int i) // Bolean : en fonction du "i", cree l'image et place son contenu dans la fenetre ou la detruit. Appelee dans ft_draw
{
	int		size;
	int		endian;
	int		bpp;

	if (i == 1)
	{
		w->img_ptr = mlx_new_image(w->mlx, 800, 500);
		w->content = mlx_get_data_addr(w->img_ptr, &bpp, &size, &endian);
	}
	if (i == 2)
	{
		mlx_put_image_to_window(w->mlx, w->win, w->img_ptr, 0, 0);
		mlx_destroy_image(w->mlx, w->img_ptr);
	}
}

int			loop_event(t_window *w) // fonction indispensable de la MLX (voir dans le main)
{
	ft_draw(w);
	return (0);
}

void		ft_fillmap(t_window *w, char **s, int *x, int y) // remplit la map grace a un atoi tout simple.
{
	int		i;

	i = 0;
	while (s[i] && *x != w->x_max)
	{
		w->map[y][*x] = ft_atoi(s[i]);
		(*x)++;
		i++;
	}
	while (*x != w->x_max)
	{
		w->map[y][*x] = BUFF;
		(*x)++;
	}
}

void		ft_exit(char *message)
{
	ft_putendl(message);
	exit(0);
}
