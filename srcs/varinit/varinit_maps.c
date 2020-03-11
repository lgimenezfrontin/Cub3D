/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_maps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:55:34 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/01 16:29:45 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_maps(t_st *st)
{
	st->maps.nbrmaps = 0;
	st->maps.tabmaps = NULL;
	st->maps.tabmapval = NULL;
	st->maps.sizemapx = 0;
	st->maps.sizemapy = 0;
	st->maps.startset = 0;
}
