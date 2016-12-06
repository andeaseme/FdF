/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pntcxt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:15:09 by aphan             #+#    #+#             */
/*   Updated: 2016/11/22 22:29:42 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_poscxt(t_fdf *p, t_xyzc xy1, t_xyzc xy2, int dxy[])
{
	int		eps;

	eps = 0;
	if (dxy[0] >= dxy[1])
		while (xy1.x <= xy2.x)
		{
			if (xy1.x >= 0 && xy1.y >= 0)
				mlx_pixel_put(p->mlx, p->win, xy1.x, xy1.y,
						fdf_color(*p, xy1, xy2, dxy));
			eps += dxy[1];
			if ((eps << 1) >= dxy[0] && ++xy1.y)
				eps -= dxy[0];
			xy1.x++;
		}
	else
		while (xy1.y <= xy2.y)
		{
			if (xy1.x >= 0 && xy1.y >= 0)
				mlx_pixel_put(p->mlx, p->win, xy1.x, xy1.y,
						fdf_color(*p, xy1, xy2, dxy));
			eps += dxy[0];
			if ((eps << 1) >= dxy[1] && ++xy1.x)
				eps -= dxy[1];
			xy1.y++;
		}
}

static void		fdf_negcxt(t_fdf *p, t_xyzc xy1, t_xyzc xy2, int dxy[])
{
	int		eps;

	eps = 0;
	if (dxy[0] >= -dxy[1])
		while (xy1.x <= xy2.x)
		{
			if (xy1.x >= 0 && xy1.y >= 0)
				mlx_pixel_put(p->mlx, p->win, xy1.x, xy1.y,
						fdf_color(*p, xy1, xy2, dxy));
			eps += dxy[1];
			if ((eps << 1) <= -dxy[0] && --xy1.y)
				eps += dxy[0];
			xy1.x++;
		}
	else
		while (xy1.y >= xy2.y)
		{
			if (xy1.x >= 0 && xy1.y >= 0)
				mlx_pixel_put(p->mlx, p->win, xy1.x, xy1.y,
						fdf_color(*p, xy1, xy2, dxy));
			eps += dxy[0];
			if ((eps << 1) >= dxy[1] && ++xy1.x)
				eps += dxy[1];
			xy1.y--;
		}
}

void			fdf_pntcxt(t_fdf *p, t_xyzc xy1, t_xyzc xy2)
{
	int		dxy[2];

	if (xy1.x > xy2.x)
	{
		ft_intswap(&xy1.x, &xy2.x);
		ft_intswap(&xy1.y, &xy2.y);
		ft_intswap(&xy1.z, &xy2.z);
	}
	dxy[1] = xy2.y - xy1.y;
	dxy[0] = xy2.x - xy1.x;
	if (dxy[1] >= 0)
		fdf_poscxt(p, xy1, xy2, dxy);
	else
		fdf_negcxt(p, xy1, xy2, dxy);
}
