/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:58:35 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/07 17:00:20 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_keys_movefwd(t_st *st)
{
	int	**lvl;

	lvl = st->maps.tabmaps[st->coor.currlvl];
	if (ft_iswalkable(lvl[(int)(st->coor.posx
			+ st->coor.dirx * st->spd.movespeed + 0.2)]
			[(int)(st->coor.posy)]) == 1
			&& ft_iswalkable(lvl[(int)(st->coor.posx
			+ st->coor.dirx * st->spd.movespeed - 0.2)]
			[(int)(st->coor.posy)]) == 1)
		st->coor.posx += st->coor.dirx * st->spd.movespeed;
	if (ft_iswalkable(lvl[(int)(st->coor.posx)][
			(int)(st->coor.posy
			+ st->coor.diry * st->spd.movespeed + 0.2)]) == 1
			&& ft_iswalkable(lvl[(int)(st->coor.posx)][
			(int)(st->coor.posy
			+ st->coor.diry * st->spd.movespeed - 0.2)]) == 1)
		st->coor.posy += st->coor.diry * st->spd.movespeed;
}

void	ft_keys_movebwd(t_st *st)
{
	int	**lvl;

	lvl = st->maps.tabmaps[st->coor.currlvl];
	if (ft_iswalkable(lvl[(int)(st->coor.posx
			- st->coor.dirx * st->spd.movespeed + 0.2)]
			[(int)(st->coor.posy)]) == 1
			&& ft_iswalkable(lvl[(int)(st->coor.posx
			- st->coor.dirx * st->spd.movespeed - 0.2)]
			[(int)(st->coor.posy)]) == 1)
		st->coor.posx -= st->coor.dirx * st->spd.movespeed;
	if (ft_iswalkable(lvl[(int)(st->coor.posx)][
			(int)(st->coor.posy
			- st->coor.diry * st->spd.movespeed + 0.2)]) == 1
			&& ft_iswalkable(lvl[(int)(st->coor.posx)][
			(int)(st->coor.posy
			- st->coor.diry * st->spd.movespeed - 0.2)]) == 1)
		st->coor.posy -= st->coor.diry * st->spd.movespeed;
}

void	ft_keys_moveleft(t_st *st)
{
	int	**lvl;

	lvl = st->maps.tabmaps[st->coor.currlvl];
	if (ft_iswalkable(lvl[(int)(st->coor.posx
				- st->rayc.planex * st->spd.movespeed + 0.2)][
				(int)(st->coor.posy)]) == 1
				&& ft_iswalkable(lvl[(int)(st->coor.posx
				- st->rayc.planex * st->spd.movespeed - 0.2)][
				(int)(st->coor.posy)]) == 1)
		st->coor.posx -= st->rayc.planex * st->spd.movespeed;
	if (ft_iswalkable(lvl[(int)(st->coor.posx)][
				(int)(st->coor.posy
				- st->rayc.planey * st->spd.movespeed + 0.2)]) == 1
				&& ft_iswalkable(lvl[(int)(st->coor.posx)][
				(int)(st->coor.posy
				- st->rayc.planey * st->spd.movespeed - 0.2)]) == 1)
		st->coor.posy -= st->rayc.planey * st->spd.movespeed;
}

void	ft_keys_moveright(t_st *st)
{
	int	**lvl;

	lvl = st->maps.tabmaps[st->coor.currlvl];
	if (ft_iswalkable(lvl[(int)(st->coor.posx
				+ st->rayc.planex * st->spd.movespeed + 0.2)][
				(int)(st->coor.posy)]) == 1
				&& ft_iswalkable(lvl[(int)(st->coor.posx
				+ st->rayc.planex * st->spd.movespeed - 0.2)][
				(int)(st->coor.posy)]) == 1)
		st->coor.posx += st->rayc.planex * st->spd.movespeed;
	if (ft_iswalkable(lvl[(int)(st->coor.posx)][
				(int)(st->coor.posy
				+ st->rayc.planey * st->spd.movespeed + 0.2)]) == 1
				&& ft_iswalkable(lvl[(int)(st->coor.posx)][
				(int)(st->coor.posy
				+ st->rayc.planey * st->spd.movespeed - 0.2)]) == 1)
		st->coor.posy += st->rayc.planey * st->spd.movespeed;
}
