/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayc_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:23:55 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/04 19:28:03 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_rayc_ceiling(t_st *st)
{
	st->win.winx = 0;
	st->win.winy = 0;
	while (st->win.winy < st->win.winh / 2)
	{
		while (st->win.winx <= st->win.winw)
		{
			*(st->mlx.img_data + st->win.winx
				+ (st->win.winy * st->win.winw)) = st->pars.clr_c;
			st->win.winx++;
		}
		st->win.winx = 0;
		st->win.winy++;
	}
}
