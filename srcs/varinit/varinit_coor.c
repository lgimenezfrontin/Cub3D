/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_coor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:17:45 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/27 18:20:12 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_coor(t_st *st)
{
	st->coor.currlvl = 0;
	st->coor.posx = 0;
	st->coor.posy = 0;
	st->coor.dirx = 0;
	st->coor.diry = 0;
	st->coor.olddirx = 0;
}
