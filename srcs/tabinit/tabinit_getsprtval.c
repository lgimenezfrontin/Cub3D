/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabinit_getsprtval.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:13:14 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/03 15:27:14 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_tabinit_getsprtval_loop(t_st *st, int j, int k, int *l)
{
	int	i;

	i = 0;
	while (i < st->maps.tabmapval[k][MAP_W])
	{
		if (ft_issprite(st->maps.tabmaps[k][j][i]) == 1)
		{
			st->sprt.tabsprtposx[k][*l] = (double)j + 0.5;
			st->sprt.tabsprtposy[k][*l] = (double)i + 0.5;
			if (st->maps.tabmaps[k][j][i] == '2')
				st->sprt.tabsprttype[k][*l] = 0;
			(*l)++;
		}
		i++;
	}
}

void	ft_tabinit_getsprtval(t_st *st)
{
	int	j;
	int	k;
	int	l;

	k = 0;
	while (k < st->maps.nbrmaps)
	{
		l = 0;
		j = 0;
		while (j < st->maps.tabmapval[k][MAP_H])
		{
			ft_tabinit_getsprtval_loop(st, j, k, &l);
			j++;
		}
		k++;
	}
}
