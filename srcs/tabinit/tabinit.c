/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:31:24 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/04 17:42:42 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_tabinit(t_st *st)
{
	ft_tabinit_gettex(st);
	ft_tabinit_getsprt(st);
	ft_tabinit_distandorder(st);
	ft_tabinit_sprtval(st);
	ft_tabinit_getsprtval(st);
}
