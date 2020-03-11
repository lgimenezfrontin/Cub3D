/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_rayc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:23:04 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/27 18:36:43 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_rayc(t_st *st)
{
	st->rayc.planex = 0;
	st->rayc.planey = 0;
	st->rayc.oldplanex = 0;
	st->rayc.raydirx = 0;
	st->rayc.raydiry = 0;
	st->rayc.mapx = 0;
	st->rayc.mapy = 0;
	st->rayc.sidedistx = 0;
	st->rayc.sidedisty = 0;
	st->rayc.deltadistx = 0;
	st->rayc.deltadisty = 0;
	st->rayc.stepx = 0;
	st->rayc.stepy = 0;
}
