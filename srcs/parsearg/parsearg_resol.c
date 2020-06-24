/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_resol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:34:27 by lgimenez          #+#    #+#             */
/*   Updated: 2020/06/11 19:07:55 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_parsearg_resol_getvalue(t_st *st, char **line, char xy)
{
	while (**line == ' ')
		(*line)++;
	if (**line == '\0')
		ft_error(st, -12);
	if (ft_isdigit(**line) == 0)
		ft_error(st, -13);
	if (xy == 'w')
	{
		st->win.winw = ft_atoi(*line);
		if (st->win.winw <= 0)
			ft_error(st, -999);
	}
	if (xy == 'h')
	{
		st->win.winh = ft_atoi(*line);
		if (st->win.winh <= 0)
			ft_error(st, -999);
	}
}

void	ft_parsearg_resol(t_st *st, char *line)
{
	if (st->pars.parsedresol == 1)
		ft_error(st, -10);
	if (st->maps.nbrmaps > 0)
		ft_error(st, -11);
	ft_parsearg_resol_getvalue(st, &line, 'w');
	if (st->win.winw > st->win.maxw)
		st->win.winw = st->win.maxw;
	while (ft_isdigit(*line) == 1)
		line++;
	if (*line == '\0')
		ft_error(st, -12);
	if (*line != ' ')
		ft_error(st, -13);
	ft_parsearg_resol_getvalue(st, &line, 'h');
	if (st->win.winh > st->win.maxh)
		st->win.winh = st->win.maxh;
	while (ft_isdigit(*line) == 1)
		line++;
	while (*line == ' ')
		line++;
	if (*line != '\0')
		ft_error(st, -13);
	st->pars.parsedresol = 1;
}
