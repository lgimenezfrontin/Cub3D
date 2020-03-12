/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayc_drawwalls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:04:28 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/12 22:09:42 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_rayc_drawwalls_loop(t_st *st, int side)
{
	while (st->win.winy < st->draw.drawend)
	{
		st->tex.texy = ((((st->win.winy) * 256 - st->win.winh * 128
					+ st->draw.lineheight * 128)
					* st->tex.tex_h[0][side]) / st->draw.lineheight) / 256;
		st->draw.color = st->tex.tex_data[0][side][
			(st->tex.tex_w[0][side] * st->tex.texy) + st->tex.texx];
		if (side == 1 || side == 3)
			st->draw.color = (st->draw.color >> 1) & 8355711;
		*(st->mlx.img_data + st->win.winx
			+ (st->win.winw * st->win.winy)) = st->draw.color;
		st->win.winy++;
	}
}

void	ft_rayc_drawwalls(t_st *st)
{
	int				side;

	side = st->wall.side;
	if (side == 0 || side == 2)
		st->wall.wallx = st->coor.posy + st->wall.walldist * st->rayc.raydiry;
	else
		st->wall.wallx = st->coor.posx + st->wall.walldist * st->rayc.raydirx;
	st->wall.wallx -= floor((st->wall.wallx));
	st->tex.texx = (int)(st->wall.wallx * (double)(st->tex.tex_w[0][side]));
	if ((side == 0 || side == 2) && st->rayc.raydirx > 0)
		st->tex.texx = st->tex.tex_w[0][side] - st->tex.texx - 1;
	if ((side == 1 || side == 3) && st->rayc.raydiry < 0)
		st->tex.texx = st->tex.tex_w[0][side] - st->tex.texx - 1;
	st->tex.texstep = 1.0 * st->tex.tex_h[0][side] / st->draw.lineheight;
	st->tex.texpos = (st->draw.drawstart - st->win.winh / 2
		+ st->draw.lineheight / 2) * st->tex.texstep;
	st->win.winy = st->draw.drawstart;
	ft_rayc_drawwalls_loop(st, side);
}
