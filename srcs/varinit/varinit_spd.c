/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_spd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:20:25 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/27 18:21:19 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_spd(t_st *st)
{
	st->spd.movespeed = 0;
	st->spd.rotspeed = 0;
}
