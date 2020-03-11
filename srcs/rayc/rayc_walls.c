/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayc_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:49:26 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/07 17:00:24 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_rayc_walls_calculate(t_st *st)
{
	if (st->wall.side == 0 || st->wall.side == 2)
		st->wall.walldist = (st->rayc.mapx - st->coor.posx
			+ ((1 - st->rayc.stepx) / 2)) / st->rayc.raydirx;
	else
		st->wall.walldist = (st->rayc.mapy - st->coor.posy
			+ ((1 - st->rayc.stepy) / 2)) / st->rayc.raydiry;
	st->draw.lineheight = (int)(st->win.winh / st->wall.walldist);
	st->draw.drawstart = (-st->draw.lineheight / 2) + (st->win.winh / 2);
	if (st->draw.drawstart < 0)
		st->draw.drawstart = 0;
	st->draw.drawend = (st->draw.lineheight / 2) + (st->win.winh / 2);
	if (st->draw.drawend >= st->win.winh)
		st->draw.drawend = st->win.winh - 1;
}

void	ft_rayc_walls_dda(t_st *st)
{
	st->wall.hit = 0;
	while (st->wall.hit == 0)
	{
		if (st->rayc.sidedistx < st->rayc.sidedisty)
		{
			st->rayc.sidedistx += st->rayc.deltadistx;
			st->rayc.mapx += st->rayc.stepx;
			if (st->rayc.stepx < 0)
				st->wall.side = 2;
			else
				st->wall.side = 0;
		}
		else
		{
			st->rayc.sidedisty += st->rayc.deltadisty;
			st->rayc.mapy += st->rayc.stepy;
			if (st->rayc.stepy < 0)
				st->wall.side = 1;
			else
				st->wall.side = 3;
		}
		if (ft_iswall(st->maps.tabmaps[st->coor.currlvl][st->rayc.mapx][
				st->rayc.mapy]) == 1)
			st->wall.hit = 1;
	}
}

void	ft_rayc_walls_step(t_st *st)
{
	if (st->rayc.raydirx < 0)
	{
		st->rayc.stepx = -1;
		st->rayc.sidedistx = (st->coor.posx - st->rayc.mapx)
			* st->rayc.deltadistx;
	}
	else
	{
		st->rayc.stepx = 1;
		st->rayc.sidedistx = (st->rayc.mapx + 1.0 - st->coor.posx)
			* st->rayc.deltadistx;
	}
	if (st->rayc.raydiry < 0)
	{
		st->rayc.stepy = -1;
		st->rayc.sidedisty = (st->coor.posy - st->rayc.mapy)
			* st->rayc.deltadisty;
	}
	else
	{
		st->rayc.stepy = 1;
		st->rayc.sidedisty = (st->rayc.mapy + 1.0 - st->coor.posy)
			* st->rayc.deltadisty;
	}
}

void	ft_rayc_walls_ray(t_st *st)
{
	double	camerax;

	camerax = ((2 * st->win.winx) / (double)st->win.winw) - 1;
	st->rayc.raydirx = st->coor.dirx + (st->rayc.planex * camerax);
	st->rayc.raydiry = st->coor.diry + (st->rayc.planey * camerax);
	st->rayc.mapx = (int)st->coor.posx;
	st->rayc.mapy = (int)st->coor.posy;
	st->rayc.deltadistx = fabs(1 / st->rayc.raydirx);
	st->rayc.deltadisty = fabs(1 / st->rayc.raydiry);
}

void	ft_rayc_walls(t_st *st)
{
	st->win.winx = 0;
	st->win.winy = 0;
	while (st->win.winx < st->win.winw)
	{
		ft_rayc_walls_ray(st);
		ft_rayc_walls_step(st);
		ft_rayc_walls_dda(st);
		ft_rayc_walls_calculate(st);
		ft_rayc_drawwalls(st);
		st->wall.tabwalldist[st->win.winx] = st->wall.walldist;
		st->win.winx++;
	}
}
