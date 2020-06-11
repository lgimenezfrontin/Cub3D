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
		st->win.winw = ft_atoi(*line);
	if (xy == 'h')
		st->win.winh = ft_atoi(*line);
}

void	ft_parsearg_resol(t_st *st, char *line)
{
	if (st->pars.parsedresol == 1)
		ft_error(st, -10);
	if (st->maps.nbrmaps > 0)
		ft_error(st, -11);
	ft_parsearg_resol_getvalue(st, &line, 'w');
	if (st->win.winw > 2560)
		st->win.winw = 2560;
	while (ft_isdigit(*line) == 1)
		line++;
	if (*line == '\0')
		ft_error(st, -12);
	if (*line != ' ')
		ft_error(st, -13);
	ft_parsearg_resol_getvalue(st, &line, 'h');
	if (st->win.winh > 1440)
		st->win.winh = 1440;
	while (ft_isdigit(*line) == 1)
		line++;
	while (*line == ' ')
		line++;
	if (*line != '\0')
		ft_error(st, -13);
	st->pars.parsedresol = 1;
}
