/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabinit_distandorder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:22:37 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/04 18:34:07 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_tabinit_distandorder_sprtorder(t_st *st)
{
	int	**t1;
	int	*t2;
	int	i;

	if (!(t1 = malloc(sizeof(int*) * st->maps.nbrmaps)))
		ft_error(st, -14);
	st->sprt.tabsprtorder = t1;
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		st->sprt.tabsprtorder[i] = NULL;
		i++;
	}
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		if (st->maps.tabmapval[i][N_SPRT] > 0)
		{
			if (!(t2 = malloc(sizeof(int) * st->maps.tabmapval[i][N_SPRT])))
				ft_error(st, -14);
			st->sprt.tabsprtorder[i] = t2;
		}
		i++;
	}
}

void	ft_tabinit_distandorder_sprtdist(t_st *st)
{
	double	**t1;
	double	*t2;
	int		i;

	if (!(t1 = malloc(sizeof(double*) * st->maps.nbrmaps)))
		ft_error(st, -14);
	st->sprt.tabsprtdist = t1;
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		st->sprt.tabsprtdist[i] = NULL;
		i++;
	}
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		if (st->maps.tabmapval[i][N_SPRT] > 0)
		{
			if (!(t2 = malloc(sizeof(double) * st->maps.tabmapval[i][N_SPRT])))
				ft_error(st, -14);
			st->sprt.tabsprtdist[i] = t2;
		}
		i++;
	}
}

void	ft_tabinit_distandorder_walldist(t_st *st)
{
	double	*tmp;

	if (!(tmp = malloc(sizeof(double) * st->win.winw)))
		ft_error(st, -14);
	st->wall.tabwalldist = tmp;
}

void	ft_tabinit_distandorder(t_st *st)
{
	ft_tabinit_distandorder_walldist(st);
	ft_tabinit_distandorder_sprtdist(st);
	ft_tabinit_distandorder_sprtorder(st);
}
