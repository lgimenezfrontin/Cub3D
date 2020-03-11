/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_sprt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:13:56 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/07 14:29:32 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_sprt_loop(t_st *st)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		st->sprt.pathsprt[i] = NULL;
		st->sprt.sprt_ptr[i] = NULL;
		st->sprt.sprt_data[i] = NULL;
		st->sprt.sprt_bpp[i] = 0;
		st->sprt.sprt_sl[i] = 0;
		st->sprt.sprt_end[i] = 0;
		st->sprt.sprt_w[i] = 0;
		st->sprt.sprt_h[i] = 0;
		i++;
	}
}

void	ft_varinit_sprt(t_st *st)
{
	ft_varinit_sprt_loop(st);
	st->sprt.tabsprtposx = NULL;
	st->sprt.tabsprtposy = NULL;
	st->sprt.tabsprttype = NULL;
	st->sprt.tabsprtdist = NULL;
	st->sprt.tabsprtorder = NULL;
	st->sprt.transformx = 0;
	st->sprt.transformy = 0;
	st->sprt.sprtscreenw = 0;
	st->sprt.sprtscreenh = 0;
	st->sprt.sprtscreenx = 0;
	st->sprt.drawstartx = 0;
	st->sprt.drawendx = 0;
	st->sprt.drawstarty = 0;
	st->sprt.drawendy = 0;
	st->sprt.stripe = 0;
	st->sprt.sprtx = 0;
	st->sprt.sprty = 0;
}
