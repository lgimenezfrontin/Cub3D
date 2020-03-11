/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:00:28 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/06 19:03:23 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_tex_loop(t_st *st, int j)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		st->tex.pathtex[j][i] = NULL;
		st->tex.tex_ptr[j][i] = NULL;
		st->tex.tex_data[j][i] = NULL;
		st->tex.tex_bpp[j][i] = 0;
		st->tex.tex_sl[j][i] = 0;
		st->tex.tex_end[j][i] = 0;
		st->tex.tex_w[j][i] = 0;
		st->tex.tex_h[j][i] = 0;
		i++;
	}
}

void	ft_varinit_tex(t_st *st)
{
	int	j;

	j = 0;
	while (j < 5)
	{
		ft_varinit_tex_loop(st, j);
		j++;
	}
	st->tex.texx = 0;
	st->tex.texy = 0;
	st->tex.texstep = 0;
	st->tex.texpos = 0;
}
