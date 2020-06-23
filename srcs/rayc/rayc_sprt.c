/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayc_sprt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:38:41 by lgimenez          #+#    #+#             */
/*   Updated: 2020/06/23 16:31:16 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_rayc_sprt_stripeloop(t_st *st)
{
	while (st->sprt.stripe < st->sprt.drawendx)
	{
		st->sprt.sprtx = (int)(256 * (st->sprt.stripe
			- (-st->sprt.sprtscreenw / 2 + st->sprt.sprtscreenx))
			* st->sprt.sprt_w[0] / st->sprt.sprtscreenw) / 256;
		if (st->sprt.transformy > 0 && st->sprt.stripe > 0
				&& st->sprt.stripe < st->win.winw
				&& st->sprt.transformy < st->wall.tabwalldist[st->sprt.stripe])
		{
			st->win.winy = st->sprt.drawstarty;
			while (st->win.winy < st->sprt.drawendy)
			{
				st->sprt.sprty = ((((st->win.winy) * 256 - st->win.winh * 128
					+ st->sprt.sprtscreenh * 128)
					* st->sprt.sprt_h[0]) / st->sprt.sprtscreenh) / 256;
				st->draw.color = st->sprt.sprt_data[0][(st->sprt.sprt_w[0]
					* st->sprt.sprty) + st->sprt.sprtx];
				if ((st->draw.color & 0x00FFFFFF) != 0)
					*(st->mlx.img_data + st->sprt.stripe + (st->win.winw
					* st->win.winy)) = st->draw.color;
				st->win.winy++;
			}
		}
		st->sprt.stripe++;
	}
}

void	ft_rayc_sprt_varinit(t_st *st, int i)
{
	int		currlvl;
	int		*sprtorder;

	currlvl = st->coor.currlvl;
	sprtorder = st->sprt.tabsprtorder[currlvl];
	st->sprt.transformx = (1.0 / (st->rayc.planex * st->coor.diry
		- st->coor.dirx * st->rayc.planey)) * (st->coor.diry
		* (st->sprt.tabsprtposx[currlvl][sprtorder[i]] - st->coor.posx)
		- st->coor.dirx * (st->sprt.tabsprtposy[currlvl][sprtorder[i]]
		- st->coor.posy));
	st->sprt.transformy = (1.0 / (st->rayc.planex * st->coor.diry
		- st->coor.dirx * st->rayc.planey)) * (-st->rayc.planey
		* (st->sprt.tabsprtposx[currlvl][sprtorder[i]] - st->coor.posx)
		+ st->rayc.planex * (st->sprt.tabsprtposy[currlvl][sprtorder[i]]
		- st->coor.posy));
	st->sprt.sprtscreenx = (int)((st->win.winw / 2)
		* (1 + st->sprt.transformx / st->sprt.transformy));
	st->sprt.sprtscreenh = abs((int)(st->win.winh / st->sprt.transformy));
}

void	ft_rayc_sprt_drawloop(t_st *st)
{
	int	i;

	i = 0;
	while (i < st->maps.tabmapval[st->coor.currlvl][N_SPRT])
	{
		ft_rayc_sprt_varinit(st, i);
		st->sprt.drawstarty = -st->sprt.sprtscreenh / 2 + st->win.winh / 2;
		if (st->sprt.drawstarty < 0)
			st->sprt.drawstarty = 0;
		st->sprt.drawendy = st->sprt.sprtscreenh / 2 + st->win.winh / 2;
		if (st->sprt.drawendy >= st->win.winh)
			st->sprt.drawendy = st->win.winh - 1;
		st->sprt.sprtscreenw = abs((int)(st->win.winh / (st->sprt.transformy)));
		st->sprt.drawstartx = -st->sprt.sprtscreenw / 2 + st->sprt.sprtscreenx;
		if (st->sprt.drawstartx < 0)
			st->sprt.drawstartx = 0;
		st->sprt.drawendx = st->sprt.sprtscreenw / 2 + st->sprt.sprtscreenx;
		if (st->sprt.drawendx >= st->win.winw)
			st->sprt.drawendx = st->win.winw - 1;
		st->sprt.stripe = st->sprt.drawstartx;
		ft_rayc_sprt_stripeloop(st);
		i++;
	}
}

void	ft_rayc_sprt_sortsprt(int *order, double *dist, int amount)
{
	int		i;
	int		j;
	double	tmp2;

	i = 0;
	while (i < amount)
	{
		j = i + 1;
		while (j < amount)
		{
			if (dist[i] < dist[j])
			{
				ft_swap(&order[i], &order[j]);
				tmp2 = dist[i];
				dist[i] = dist[j];
				dist[j] = tmp2;
				i = 0;
				j = i + 1;
			}
			j++;
		}
		i++;
	}
}

void	ft_rayc_sprt(t_st *st)
{
	int		currlvl;
	int		*sprtorder;
	double	*sprtdist;
	int		i;

	currlvl = st->coor.currlvl;
	sprtorder = st->sprt.tabsprtorder[currlvl];
	sprtdist = st->sprt.tabsprtdist[currlvl];
	i = 0;
	while (i < st->maps.tabmapval[currlvl][N_SPRT])
	{
		sprtorder[i] = i;
		sprtdist[i] = sqrt(((st->coor.posx - st->sprt.tabsprtposx[currlvl][i])
			* (st->coor.posx - st->sprt.tabsprtposx[currlvl][i])
			+ (st->coor.posy - st->sprt.tabsprtposy[currlvl][i])
			* (st->coor.posy - st->sprt.tabsprtposy[currlvl][i])));
		i++;
	}
	if (st->maps.tabmapval[currlvl][N_SPRT] > 1)
		ft_rayc_sprt_sortsprt(sprtorder,
			sprtdist, st->maps.tabmapval[currlvl][N_SPRT]);
	ft_rayc_sprt_drawloop(st);
}
