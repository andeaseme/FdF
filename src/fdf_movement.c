/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:05:21 by aphan             #+#    #+#             */
/*   Updated: 2016/11/22 22:08:32 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_lstiter(t_fdf *p, void (*f)(t_xyzc *xy, t_fdf *p))
{
	t_list	*field;
	size_t	c;

	field = p->field;
	while (field)
	{
		c = 0;
		while (c < field->content_size)
		{
			f(&(((t_xyzc *)(field->content))[c]), p);
			c++;
		}
		field = field->next;
	}
}

void		fdf_zoom(t_xyzc *xy, t_fdf *p)
{
	int		size;

	size = (p->zoom * PIX) / 100;
	xy->x = p->wcentx - ((p->centx - xy->x) * size);
	xy->y = p->wcenty - ((p->centy - xy->y) * size);
	xy->z *= size;
}

void		fdf_translate(t_xyzc *xy, t_fdf *p)
{
	xy->x += p->tranx;
	xy->y += p->trany;
}

void		fdf_rotate(t_xyzc *xy, t_fdf *p)
{
	double	a;
	double	x;
	double	y;
	double	z;

	a = (DEG * M_PI) / 180;
	x = rint((xy->x - p->wcentx) * cos(a * p->roty)
			- (xy->z) * sin(a * p->roty) + p->wcentx);
	z = rint((xy->x - p->wcentx) * sin(a * p->roty)
			+ (xy->z) * cos(a * p->roty));
	xy->x = x;
	y = rint((xy->y - p->wcenty) * cos(a * p->rotx)
			- (z) * sin(a * p->rotx) + p->wcenty);
	xy->y = y;
	x = rint((xy->x - p->wcentx) * cos(a * p->rotz)
			- (xy->y - p->wcenty) * sin(a * p->rotz) + p->wcentx);
	y = rint((xy->x - p->wcentx) * sin(a * p->rotz)
			+ (xy->y - p->wcenty) * cos(a * p->rotz) + p->wcenty);
	xy->x = x;
	xy->y = y;
}
