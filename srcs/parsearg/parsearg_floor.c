/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:34:24 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/09 18:03:41 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_parsearg_floor_text(char **line)
{
	(void)line;
}

int		ft_parsearg_floor_getvalue(t_st *st, char **line)
{
	int		ret;

	while (**line == ' ')
		(*line)++;
	if (ft_isdigit(**line) == 0)
		ft_error(st, -12);
	ret = ft_atoi(*line);
	while (ft_isdigit(**line) == 1)
		(*line)++;
	return (ret);
}

void	ft_parsearg_floor_color(t_st *st, char **line)
{
	st->pars.fr = ft_parsearg_floor_getvalue(st, line);
	if (**line != ',')
		ft_error(st, -15);
	(*line)++;
	st->pars.fg = ft_parsearg_floor_getvalue(st, line);
	if (**line != ',')
		ft_error(st, -15);
	(*line)++;
	st->pars.fb = ft_parsearg_floor_getvalue(st, line);
	if (!(st->pars.fr >= 0 && st->pars.fr <= 255)
			|| !(st->pars.fg >= 0 && st->pars.fg <= 255)
			|| !(st->pars.fb >= 0 && st->pars.fb <= 255))
		ft_error(st, -16);
	st->pars.clr_f = (st->pars.fr * 65536) + (st->pars.fg * 256) + st->pars.fb;
}

void	ft_parsearg_floor(t_st *st, char *line)
{
	if (st->pars.parsedfloor == 1)
		ft_error(st, -10);
	if (st->maps.nbrmaps > 0)
		ft_error(st, -11);
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line) == 1)
		ft_parsearg_floor_color(st, &line);
	else if (*line != '\0')
		ft_parsearg_floor_text(&line);
	else
		ft_error(st, -12);
	while (*line == ' ')
		line++;
	if (*line != '\0')
		ft_error(st, -13);
	st->pars.parsedfloor = 1;
}
