/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_mapvalid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 19:21:29 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 13:04:10 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_parsearg_mapvalid_startval(t_st *st, int x, int y, int i)
{
	if (st->maps.startset == 0)
	{
		st->maps.tabmapval[st->maps.nbrmaps - 1][ST_X] = x;
		st->maps.tabmapval[st->maps.nbrmaps - 1][ST_Y] = y;
		st->maps.tabmapval[st->maps.nbrmaps - 1][ST_DIR] = i;
		st->maps.startset = 1;
	}
	else
		ft_error(st, -19);
}

void	ft_parsearg_mapvalid_checktile(t_st *st, int x, int y, int i)
{
	if (ft_iswall(i) == 1)
	{
		if (ft_wallisvalid(st, i) == 0)
			ft_error(st, -9);
	}
	else if (ft_issprite(i) == 1)
	{
		if (ft_spriteisvalid(st, i) == 0)
			ft_error(st, -9);
		else
			st->maps.tabmapval[st->maps.nbrmaps - 1][N_SPRT]++;
	}
	else if (i == 'N' || i == 'E' || i == 'S' || i == 'W')
		ft_parsearg_mapvalid_startval(st, x, y, i);
	else if (i != '0' && i != ' ')
		ft_error(st, -20);
}

void	ft_parsearg_mapvalid_midlines(t_st *st, int *j)
{
	int	**map;
	int	i;

	map = st->maps.tabmaps[st->maps.nbrmaps - 1];
	while (*j < st->maps.tabmapval[st->maps.nbrmaps - 1][MAP_H] - 1)
	{
		i = 0;
		if (ft_iswalkable(map[*j][i]) == 1 || ft_issprite(map[*j][i]) == 1)
			ft_error(st, -17);
		ft_parsearg_mapvalid_checktile(st, *j, i, map[*j][i]);
		i++;
		while (i < st->maps.tabmapval[st->maps.nbrmaps - 1][MAP_W] - 1)
		{
			if (ft_iswalkable(map[*j][i]) == 1 && (map[*j][i - 1] == ' '
					|| map[*j][i + 1] == ' ' || map[(*j) - 1][i] == ' '
					|| map[(*j) + 1][i] == ' '))
				ft_error(st, -17);
			ft_parsearg_mapvalid_checktile(st, *j, i, map[*j][i]);
			i++;
		}
		if (ft_iswalkable(map[*j][i]) == 1 || ft_issprite(map[*j][i]) == 1)
			ft_error(st, -17);
		ft_parsearg_mapvalid_checktile(st, *j, i, map[*j][i]);
		(*j)++;
	}
}

void	ft_parsearg_mapvalid_closingline(t_st *st, int j)
{
	int	*mapval;
	int	**map;
	int	i;

	mapval = st->maps.tabmapval[st->maps.nbrmaps - 1];
	map = st->maps.tabmaps[st->maps.nbrmaps - 1];
	if (mapval[MAP_W] < 2 || mapval[MAP_H] < 2)
		ft_error(st, -23);
	i = 0;
	while (i < mapval[MAP_W])
	{
		if (ft_iswalkable(map[j][i]) == 1 || ft_issprite(map[j][i]) == 1)
			ft_error(st, -17);
		ft_parsearg_mapvalid_checktile(st, j, i, map[j][i]);
		i++;
	}
}

void	ft_parsearg_mapvalid(t_st *st)
{
	int j;

	st->maps.startset = 0;
	j = 0;
	ft_parsearg_mapvalid_closingline(st, j);
	j++;
	ft_parsearg_mapvalid_midlines(st, &j);
	ft_parsearg_mapvalid_closingline(st, j);
	if (st->maps.startset == 0)
		ft_error(st, -18);
}
