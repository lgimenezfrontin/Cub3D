/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_mapvalinit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:49:01 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/06 15:45:31 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_parsearg_mapvalinit_val(t_st *st)
{
	int	*tmp;

	if (!(tmp = malloc(sizeof(int) * 6)))
		ft_error(st, -14);
	tmp[MAP_W] = st->maps.sizemapx;
	tmp[MAP_H] = st->maps.sizemapy;
	tmp[ST_X] = 0;
	tmp[ST_Y] = 0;
	tmp[ST_DIR] = 0;
	tmp[N_SPRT] = 0;
	st->maps.tabmapval[st->maps.nbrmaps - 1] = tmp;
}

void	ft_parsearg_mapvalinit(t_st *st)
{
	int	**tmp;
	int	i;

	if (!(tmp = malloc(sizeof(int*) * st->maps.nbrmaps)))
		ft_error(st, -14);
	i = 0;
	while (i < st->maps.nbrmaps - 1)
	{
		tmp[i] = NULL;
		i++;
	}
	if (st->maps.tabmapval != NULL)
	{
		i = 0;
		while (i < st->maps.nbrmaps - 1)
		{
			tmp[i] = st->maps.tabmapval[i];
			i++;
		}
		free(st->maps.tabmapval);
	}
	st->maps.tabmapval = tmp;
	ft_parsearg_mapvalinit_val(st);
	ft_parsearg_mapvalid(st);
}
