/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:01:46 by aphan             #+#    #+#             */
/*   Updated: 2016/11/22 22:25:57 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf			fdf_reset(t_fdf p)
{
	p.rotx = 0;
	p.roty = 0;
	p.rotz = 0;
	p.tranx = 0;
	p.trany = 0;
	p.wcentx = WIN_SIZE / 2;
	p.wcenty = (WIN_SIZE * 9) / 32;
	p.centx = p.xmax / 2;
	p.centy = p.ymax / 2;
	return (p);
}

static t_fdf	fdf_init(t_fdf *p)
{
	p->field = NULL;
	p->ymax = 0;
	p->xmax = 0;
	p->zmax = 0;
	p->zmin = 0;
	p->zoom = 100;
	return (*p);
}

static void		fdf(const int fd)
{
	char	*line;
	int		len;
	t_xyzc	*nbrline;
	t_fdf	p;

	p = fdf_init(&p);
	while (get_next_line(fd, &line) == 1)
	{
		len = 0;
		nbrline = fdf_nbrline(line, &p, &len);
		p.field = fdf_nbrfield(nbrline, len, &(p.field));
		p.xmax = (p.xmax < len) ? len : p.xmax;
		(p.ymax)++;
	}
	p = fdf_reset(p);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, WIN_SIZE, (WIN_SIZE * 9) / 16, "FdF");
	p.copy = ft_lstdup(p.field, sizeof(t_xyzc));
	fdf_lstiter(&p, &fdf_zoom);
	fdf_drawfield(p);
	mlx_key_hook(p.win, fdf_keyfunct, &p);
	mlx_loop(p.mlx);
}

int				main(int argc, char **argv)
{
	int		fd;

	if (argc > 1 && (fd = open(argv[1], O_RDONLY)) >= 0)
		fdf(fd);
	else
		ft_putendl("error: need proper filename");
	return (0);
}
