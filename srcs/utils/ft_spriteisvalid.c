/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spriteisvalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:42:19 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/01 16:38:39 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int		ft_spriteisvalid(t_st *st, int i)
{
	if (i == '2')
		i = 0;
	else
		return (0);
	if (st->sprt.pathsprt[i] == NULL)
		return (0);
	return (1);
}
