/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_lvl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:23:17 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/29 17:23:22 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_keys_lvlminus(t_st *st)
{
	if (st->coor.currlvl > 0)
	{
		st->coor.currlvl--;
		ft_lvlinit(st);
	}
	st->keys.keepminus = 1;
}

void	ft_keys_lvlplus(t_st *st)
{
	if (st->coor.currlvl < st->maps.nbrmaps - 1)
	{
		st->coor.currlvl++;
		ft_lvlinit(st);
	}
	st->keys.keepplus = 1;
}
