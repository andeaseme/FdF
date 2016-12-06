/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:59:38 by aphan             #+#    #+#             */
/*   Updated: 2016/11/22 22:28:36 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_colorgradient(int m)
{
	int		r[4];
	int		g[4];
	int		b[4];
	int		color;

	color = 0;
	r[0] = BOT & 0x00FF0000;
	r[1] = MID & 0x00FF0000;
	r[2] = TOP & 0x00FF0000;
	r[3] = (m < 50) ? r[0] + ((r[1] - r[0]) * m) / 50 :
		r[1] + ((r[2] - r[1]) * (m - 50)) / 50;
	color = color | (r[3] & 0x00FF0000);
	b[0] = BOT & 0x0000FF00;
	b[1] = MID & 0x0000FF00;
	b[2] = TOP & 0x0000FF00;
	b[3] = (m < 50) ? b[0] + ((b[1] - b[0]) * m) / 50 :
		b[1] + ((b[2] - b[1]) * (m - 50)) / 50;
	color = color | (b[3] & 0x00FF00);
	g[0] = BOT & 0x000000FF;
	g[1] = MID & 0x000000FF;
	g[2] = TOP & 0x000000FF;
	g[3] = (m < 50) ? g[0] + ((g[1] - g[0]) * m) / 50 :
		g[1] + ((g[2] - g[1]) * (m - 50)) / 50;
	color = color | (g[3] & 0x000000FF);
	return (color);
}

int				fdf_color(t_fdf p, t_xyzc xy, t_xyzc xy2, int dxy[])
{
	int		z;
	int		size;
	int		zrange[2];
	int		m;

	z = xy.z;
	size = (p.zoom * PIX) / 100;
	if (p.zmax == p.zmin)
		return (TOP);
	if (dxy[0])
		z = ((xy.x - (xy2.x - dxy[0])) * (xy2.z - xy.z)) / dxy[0] + xy.z;
	else if (dxy[1])
		z = ((xy.y - (xy2.y - dxy[1])) * (xy2.z - xy.z)) / dxy[1] + xy.z;
	if (z == (zrange[1] = p.zmax * size))
		return (TOP);
	if (z == (zrange[0] = p.zmin * size))
		return (BOT);
	m = (100 * (z - zrange[0])) / (zrange[1] - zrange[0]);
	return (fdf_colorgradient(m));
}
