/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabinit_sprtval.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:15:34 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/04 17:45:56 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_tabinit_sprtval_sprttype(t_st *st)
{
	int	**t1;
	int	*t2;
	int	i;

	if (!(t1 = malloc(sizeof(int*) * st->maps.nbrmaps)))
		ft_error(st, -14);
	st->sprt.tabsprttype = t1;
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		st->sprt.tabsprttype[i] = NULL;
		i++;
	}
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		if (st->maps.tabmapval[i][N_SPRT] > 0)
		{
			if (!(t2 = malloc(sizeof(int) * st->maps.tabmapval[i][N_SPRT])))
				ft_error(st, -14);
			st->sprt.tabsprttype[i] = t2;
		}
		i++;
	}
}

void	ft_tabinit_sprtval_sprtposy(t_st *st)
{
	double	**t1;
	double	*t2;
	int		i;

	if (!(t1 = malloc(sizeof(double*) * st->maps.nbrmaps)))
		ft_error(st, -14);
	st->sprt.tabsprtposy = t1;
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		st->sprt.tabsprtposy[i] = NULL;
		i++;
	}
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		if (st->maps.tabmapval[i][N_SPRT] > 0)
		{
			if (!(t2 = malloc(sizeof(double) * st->maps.tabmapval[i][N_SPRT])))
				ft_error(st, -14);
			st->sprt.tabsprtposy[i] = t2;
		}
		i++;
	}
}

void	ft_tabinit_sprtval_sprtposx(t_st *st)
{
	double	**t1;
	double	*t2;
	int		i;

	if (!(t1 = malloc(sizeof(double*) * st->maps.nbrmaps)))
		ft_error(st, -14);
	st->sprt.tabsprtposx = t1;
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		st->sprt.tabsprtposx[i] = NULL;
		i++;
	}
	i = 0;
	while (i < st->maps.nbrmaps)
	{
		if (st->maps.tabmapval[i][N_SPRT] > 0)
		{
			if (!(t2 = malloc(sizeof(double) * st->maps.tabmapval[i][N_SPRT])))
				ft_error(st, -14);
			st->sprt.tabsprtposx[i] = t2;
		}
		i++;
	}
}

void	ft_tabinit_sprtval(t_st *st)
{
	ft_tabinit_sprtval_sprtposx(st);
	ft_tabinit_sprtval_sprtposy(st);
	ft_tabinit_sprtval_sprttype(st);
}
