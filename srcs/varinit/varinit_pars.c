/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varinit_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:49:01 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/09 16:38:10 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_varinit_pars_parsedsprtloop(t_st *st)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		st->pars.parsedsprt[i] = 0;
		i++;
	}
}

void	ft_varinit_pars_parsedtexloop(t_st *st)
{
	int	i;
	int	j;

	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 4)
		{
			st->pars.parsedtex[j][i] = 0;
			i++;
		}
		j++;
	}
}

void	ft_varinit_pars(t_st *st)
{
	st->pars.line = NULL;
	st->pars.parsedresol = 0;
	ft_varinit_pars_parsedtexloop(st);
	ft_varinit_pars_parsedsprtloop(st);
	st->pars.parsedfloor = 0;
	st->pars.parsedceiling = 0;
	st->pars.retgnl = 0;
	st->pars.clr_f = 0;
	st->pars.fr = 0;
	st->pars.fg = 0;
	st->pars.fb = 0;
	st->pars.clr_c = 0;
	st->pars.cr = 0;
	st->pars.cg = 0;
	st->pars.cb = 0;
	st->pars.parsingmap = 0;
	st->pars.strmap = NULL;
}
