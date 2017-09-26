/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainparser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rweiss <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:21:21 by rweiss            #+#    #+#             */
/*   Updated: 2017/05/30 13:08:10 by rweiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				strlen_perso(char *str) // evite de faire un ft_getnbr.
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i] + 0) == 1)
		{
			j++;
			while (ft_isdigit(str[i] + 0) == 1)
				i++;
		}
		i++;
	}
	return (j);
}

void			ft_counter(char *av, t_window *w) // check si la map est lisible et enregistre les valeurs max de x et y dans la structure
{
	char		*line;
	int			x;
	int			y;
	int			n;
	int			fd;

	line = 0;
	n = 0;
	y = 0;
	x = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_exit("error : cannot open the file");
	while (get_next_line(fd, &line) == 1)
	{
		n = strlen_perso(line);
		if (n > x)
			x = n;
		y++;
		if (line)
			free(line);
	}
	close(fd);
	w->x_max = x;
	w->y_max = y;
}

void			ft_parser(char *av, t_window *w) // le parser hardcore baby
{
	char		*line;
	char		**s;
	int			y;
	int			x;
	int			fd;

	x = 0;
	y = 0;
	s = NULL;
	if (!av)
		return ;
	fd = open(av, O_RDONLY);
	w->map = (int**)malloc(sizeof(int*) * w->y_max);
	while (get_next_line(fd, &line) == 1 && y != w->y_max)
	{
		w->map[y] = (int*)malloc(sizeof(int) * w->x_max);
		s = ft_strsplit(line, ' '); // utilisation de ft_strsplit
		if (s)
			ft_fillmap(w, s, &x, y);
		x = 0;
		if (s)
			free(s);
		y++;
	}
	close(fd);
}

int				keyrelease(int keycode, t_window *w) // la fcontion qui gere les evenements lies aux touches du clavier : ESC, ZOOM, COLOR ...
{
	if (keycode == 53)
		exit(0);
	if (keycode == 89 && w->r + 10 < 255) // gere les couleurs R G B
		w->r = w->r + 10;
	if (keycode == 91 && w->g + 10 < 255)
		w->g = w->g + 10;
	if (keycode == 92 && w->b + 10 < 255)
		w->b = w->b + 10;
	if (keycode == 81) // reinitialise les couleurs a 0
	{
		w->r = 0;
		w->g = 0;
		w->b = 0;
	}
	if (keycode == 69)
		w->zoom = w->zoom + 1; // gere le zoom
	if (keycode == 78 && w->zoom - 1 > 0)
		w->zoom = w->zoom - 1;
	if (keycode == 116 && w->z_ch + 2 < 15)
		w->z_ch = w->z_ch + 2; // gere l'acentuation de la hauteur des segments
	if (keycode == 121 && w->z_ch - 2 > -15)
		w->z_ch = w->z_ch - 2;
	return (0);
}

int				main(int ac, char **av) // tous les evenements de la minilibx doivent etre ici.
{
	t_window	*w;

	if (ac != 2)
		ft_exit("usage: ./fdf extern_file");
	w = (t_window *)malloc(sizeof(t_window)); // allocation memoire de la struct
	if (ft_init_mlx(w) == 1) // initialisation
		return (0);
	ft_counter(av[1], w); // check si la map est valide
	ft_parser(av[1], w); // parse
	mlx_hook(w->win, 2, 3, keyrelease, w); // appel MLX de la fonction clavier
	mlx_loop_hook(w->mlx, &loop_event, w); // appel de la fonction qui dessine dans la fenetre
	mlx_loop(w->mlx); // obligatoire pour que ton programme boucle et dessine l'integralite de ta map
	return (0);
}
