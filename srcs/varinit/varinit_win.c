/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:16:04 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/27 18:17:41 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_win(t_st *st)
{
	st->win.maxw = 0;
	st->win.maxh = 0;
	st->win.winw = 0;
	st->win.winh = 0;
	st->win.winx = 0;
	st->win.winy = 0;
}
