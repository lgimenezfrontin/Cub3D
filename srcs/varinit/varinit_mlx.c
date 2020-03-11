/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:57:48 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/27 18:00:17 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_mlx(t_st *st)
{
	st->mlx.mlx_ptr = NULL;
	st->mlx.win_ptr = NULL;
	st->mlx.img_ptr = NULL;
	st->mlx.img_data = NULL;
	st->mlx.img_bpp = 0;
	st->mlx.img_sl = 0;
	st->mlx.img_end = 0;
}
