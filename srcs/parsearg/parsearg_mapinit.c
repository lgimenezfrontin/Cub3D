/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_mapinit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 14:42:22 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 13:46:37 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int		*ft_parsearg_mapinit_mapline(t_st *st, int linenbr, int i)
{
	int		*mapline;
	int		j;

	if (!(mapline = malloc(sizeof(int) * st->maps.sizemapx)))
		ft_error(st, -14);
	j = 0;
	while (linenbr)
	{
		i++;
		if (st->pars.strmap[i] == '\n')
			linenbr--;
	}
	i++;
	while (st->pars.strmap[i] != '\n')
	{
		mapline[j] = st->pars.strmap[i];
		i++;
		j++;
	}
	while (j < st->maps.sizemapx)
	{
		mapline[j] = ' ';
		j++;
	}
	return (mapline);
}

void	ft_parsearg_mapinit_sizemapy(t_st *st)
{
	int	i;

	st->maps.sizemapy = 0;
	i = 0;
	while (st->pars.strmap[i])
	{
		if (st->pars.strmap[i] == '\n')
			st->maps.sizemapy++;
		i++;
	}
}

int		**ft_parsearg_mapinit_map(t_st *st)
{
	int	**map;
	int	i;

	ft_parsearg_mapinit_sizemapy(st);
	if (!(map = malloc(sizeof(int*) * st->maps.sizemapy)))
		ft_error(st, -14);
	i = 0;
	while (i < st->maps.sizemapy)
	{
		map[i] = NULL;
		i++;
	}
	i = 0;
	while (i < st->maps.sizemapy)
	{
		map[i] = ft_parsearg_mapinit_mapline(st, i, -1);
		i++;
	}
	free(st->pars.strmap);
	st->pars.strmap = NULL;
	return (map);
}

void	ft_parsearg_mapinit(t_st *st)
{
	int	***tmp;
	int	i;

	st->pars.parsingmap = 0;
	if (!(tmp = malloc(sizeof(int**) * st->maps.nbrmaps)))
		ft_error(st, -14);
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		tmp[i] = NULL;
		i++;
	}
	if (st->maps.tabmaps != NULL)
	{
		i = 0;
		while (i < st->maps.nbrmaps - 1)
		{
			tmp[i] = st->maps.tabmaps[i];
			i++;
		}
		free(st->maps.tabmaps);
	}
	st->maps.tabmaps = tmp;
	st->maps.tabmaps[st->maps.nbrmaps - 1] = ft_parsearg_mapinit_map(st);
	ft_parsearg_mapvalinit(st);
}
