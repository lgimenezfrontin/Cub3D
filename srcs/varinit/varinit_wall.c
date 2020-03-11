/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:25:22 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/01 15:24:20 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_wall(t_st *st)
{
	st->wall.hit = 0;
	st->wall.side = 0;
	st->wall.walldist = 0;
	st->wall.tabwalldist = NULL;
	st->wall.wallx = 0;
}
