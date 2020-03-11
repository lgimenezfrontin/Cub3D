/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lvlinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:01:55 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/06 17:05:23 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_lvlinit(t_st *st)
{
	double	pi;

	st->coor.posx = (double)st->maps.tabmapval[st->coor.currlvl][ST_X] + 0.5;
	st->coor.posy = (double)st->maps.tabmapval[st->coor.currlvl][ST_Y] + 0.5;
	st->coor.dirx = -1;
	st->coor.diry = 0;
	st->rayc.planex = 0;
	st->rayc.planey = 0.66;
	if (st->maps.tabmapval[st->coor.currlvl][ST_DIR] == 'W')
		pi = M_PI_2;
	if (st->maps.tabmapval[st->coor.currlvl][ST_DIR] == 'S')
		pi = M_PI;
	if (st->maps.tabmapval[st->coor.currlvl][ST_DIR] == 'E')
		pi = 3 * M_PI_2;
	if (st->maps.tabmapval[st->coor.currlvl][ST_DIR] != 'N')
	{
		st->coor.olddirx = st->coor.dirx;
		st->coor.dirx = st->coor.dirx * cos(pi) - st->coor.diry * sin(pi);
		st->coor.diry = st->coor.olddirx * sin(pi) + st->coor.diry * cos(pi);
		st->rayc.oldplanex = st->rayc.planex;
		st->rayc.planex = st->rayc.planex * cos(pi) - st->rayc.planey * sin(pi);
		st->rayc.planey = st->rayc.oldplanex * sin(pi)
			+ st->rayc.planey * cos(pi);
	}
}
