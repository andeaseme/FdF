/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_fieldkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:11:03 by aphan             #+#    #+#             */
/*   Updated: 2016/11/22 22:33:44 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_keymaster(int key, t_fdf *p)
{
	if (key == 38)
		p->roty--;
	else if (key == 37)
		p->roty++;
	else if (key == 34)
		p->rotx++;
	else if (key == 40)
		p->rotx--;
	else if (key == 32)
		p->rotz--;
	else if (key == 31)
		p->rotz++;
	else if (key == 2 || key == 124)
		p->tranx += STEP;
	else if (key == 0 || key == 123)
		p->tranx -= STEP;
	else if (key == 1 || key == 125)
		p->trany += STEP;
	else if (key == 13 || key == 126)
		p->trany -= STEP;
	else if (key == 12)
		p->zoom += ZOOM;
	else if (key == 14)
		p->zoom -= ZOOM;
}

int				fdf_keyfunct(int key, t_fdf *p)
{
	if (key == 18)
	{
		p->field = ft_lstclr(&(p->field));
		p->field = ft_lstdup(p->copy, sizeof(t_xyzc));
		*p = fdf_reset(*p);
	}
	else if (key == 53)
		exit(0);
	fdf_keymaster(key, p);
	p->field = ft_lstclr(&(p->field));
	p->field = ft_lstdup(p->copy, sizeof(t_xyzc));
	fdf_lstiter(p, &fdf_zoom);
	fdf_lstiter(p, &fdf_rotate);
	fdf_lstiter(p, &fdf_translate);
	mlx_clear_window(p->mlx, p->win);
	fdf_drawfield(*p);
	return (0);
}

t_xyzc			*fdf_nbrline(char *line, t_fdf *p, int *len)
{
	char	**sp;
	char	*c;
	t_xyzc	*nbrline;

	sp = ft_strsplit(line, ' ');
	while (sp[*len])
		(*len)++;
	nbrline = malloc(sizeof(t_xyzc) * (*len));
	*len = 0;
	while (sp[*len])
	{
		nbrline[*len].x = *len;
		nbrline[*len].y = p->ymax;
		nbrline[*len].z = ft_atoi(sp[*len]);
		p->zmax = (nbrline[*len].z > p->zmax) ? nbrline[*len].z : p->zmax;
		p->zmin = (nbrline[*len].z < p->zmin) ? nbrline[*len].z : p->zmin;
		c = ft_strchr(sp[*len], ',');
		nbrline[*len].c = (c && *(++c) == '0' && (*(++c) == 'x' || *c == 'X')
				&& *(++c)) ? ft_atoi_base(c, 16) : -1;
		free(sp[*len]);
		(*len)++;
	}
	free(sp);
	free(line);
	return (nbrline);
}

void			fdf_drawfield(t_fdf p)
{
	t_xyzc	*r1;
	t_xyzc	*r2;
	size_t	c;

	while (p.field)
	{
		r1 = (t_xyzc *)p.field->content;
		if (p.field->next)
			r2 = (t_xyzc *)p.field->next->content;
		c = 0;
		while (c < p.field->content_size)
		{
			if (c + 1 < p.field->content_size)
				fdf_pntcxt(&p, r1[c], r1[c + 1]);
			if (p.field->next && c < p.field->next->content_size)
				fdf_pntcxt(&p, r1[c], r2[c]);
			c++;
		}
		p.field = p.field->next;
	}
}

t_list			*fdf_nbrfield(t_xyzc *nbrline, const int len, t_list **list)
{
	ft_lstadd(list, ft_lstnew(nbrline, sizeof(t_xyzc) * len));
	(*list)->content_size = len;
	free(nbrline);
	return (*list);
}
