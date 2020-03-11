/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayc_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:29:43 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/04 19:33:55 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_rayc_floor(t_st *st)
{
	st->win.winx = 0;
	st->win.winy = st->win.winh / 2;
	while (st->win.winy < st->win.winh - 1)
	{
		while (st->win.winx <= st->win.winw)
		{
			*(st->mlx.img_data + st->win.winx
				+ (st->win.winy * st->win.winw)) = st->pars.clr_f;
			st->win.winx++;
		}
		st->win.winx = 0;
		st->win.winy++;
	}
}
