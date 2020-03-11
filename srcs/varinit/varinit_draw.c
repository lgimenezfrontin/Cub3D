/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:27:34 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/27 18:36:18 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_draw(t_st *st)
{
	st->draw.lineheight = 0;
	st->draw.drawstart = 0;
	st->draw.drawend = 0;
	st->draw.color = 0;
}
