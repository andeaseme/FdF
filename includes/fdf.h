/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:02:57 by aphan             #+#    #+#             */
/*   Updated: 2016/11/22 23:54:11 by aphan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

# define PIX 25
# define STEP 25
# define ZOOM 5
# define DEG 5
# define WIN_SIZE 1600
# define TOP 0x00FFFF
# define MID 0xFF00FF
# define BOT 0xFFFF00

typedef struct	s_xyzc
{
	int			x;
	int			y;
	int			z;
	int			c;
}				t_xyzc;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_list		*field;
	t_list		*copy;
	int			xmax;
	int			ymax;
	int			zmax;
	int			zmin;
	int			rotx;
	int			roty;
	int			rotz;
	int			tranx;
	int			trany;
	int			zoom;
	int			centx;
	int			centy;
	int			wcentx;
	int			wcenty;
}				t_fdf;

void			fdf_pntcxt(t_fdf *p, t_xyzc xy1, t_xyzc xy2);
int				fdf_color(t_fdf p, t_xyzc xy, t_xyzc xy2, int dxy[]);
void			fdf_lstiter(t_fdf *p, void (*f)(t_xyzc *xy, t_fdf *p));
void			fdf_zoom(t_xyzc *xy, t_fdf *p);
void			fdf_translate(t_xyzc *xy, t_fdf *p);
void			fdf_rotate(t_xyzc *xy, t_fdf *p);
t_xyzc			*fdf_nbrline(char *line, t_fdf *p, int *len);
void			fdf_drawfield(t_fdf p);
t_list			*fdf_nbrfield(t_xyzc *nbrline, const int len, t_list **list);
int				fdf_keyfunct(int key, t_fdf *p);
t_fdf			fdf_reset(t_fdf p);

#endif
