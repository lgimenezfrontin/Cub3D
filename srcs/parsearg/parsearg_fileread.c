/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_fileread.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:40:19 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 13:56:03 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_parsearg_fileread_map(t_st *st, char *line)
{
	if (*line == '\0')
	{
		if (st->pars.parsingmap == 1)
			ft_parsearg_mapinit(st);
	}
	else
	{
		if (st->pars.parsingmap == 0)
			st->maps.nbrmaps++;
		st->pars.parsingmap = 1;
		ft_parsearg_mapread(st, line);
	}
}

void	ft_parsearg_fileread_spacechar(t_st *st, char *line)
{
	int	i;

	i = 0;
	if (line[i] == ' ')
	{
		while (line[i] == ' ')
			i++;
		if (!((ft_iswall(line[i]) == 1 && ft_iswalkable(line[i]) == 0)
				|| line[i] == '\0'))
			ft_error(st, -7);
	}
	if (line[i] != '\0')
	{
		if (st->pars.parsedresol == 0 || st->pars.parsedfloor == 0
				|| st->pars.parsedceiling == 0)
			ft_error(st, -9);
		st->maps.nbrmaps++;
		st->pars.parsingmap = 1;
		ft_parsearg_mapread(st, line);
	}
	else
		ft_error(st, -8);
}

void	ft_parsearg_fileread_id(t_st *st, char *line)
{
	if (*line == ' ' || (ft_iswall(*line) == 1 && ft_iswalkable(*line) == 0))
		ft_parsearg_fileread_spacechar(st, line);
	else if (*line == 'R')
		ft_parsearg_resol(st, line + 1);
	else if (*line == 'N' || *line == 'E'
			|| (*line == 'S' && *(line + 1) == 'O') || *line == 'W')
		ft_parsearg_tex_path(st, line, 0);
	else if (*line == 'T')
		ft_parsearg_tex(st, line + 1);
	else if (*line == 'S')
		ft_parsearg_sprt(st, line + 1, 0);
	else if (*line == 'F')
		ft_parsearg_floor(st, line + 1);
	else if (*line == 'C')
		ft_parsearg_ceiling(st, line + 1);
	else if (*line != '\0')
		ft_error(st, -6);
}

void	ft_parsearg_fileread(t_st *st, char *line)
{
	if (st->maps.nbrmaps == 0)
		ft_parsearg_fileread_id(st, line);
	else
		ft_parsearg_fileread_map(st, line);
}
