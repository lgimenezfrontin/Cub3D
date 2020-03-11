/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_ceiling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 21:40:57 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/09 18:02:54 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_parsearg_ceiling_text(char **line)
{
	(void)line;
}

int		ft_parsearg_ceiling_getvalue(t_st *st, char **line)
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

void	ft_parsearg_ceiling_color(t_st *st, char **line)
{
	st->pars.cr = ft_parsearg_ceiling_getvalue(st, line);
	if (**line != ',')
		ft_error(st, -15);
	(*line)++;
	st->pars.cg = ft_parsearg_ceiling_getvalue(st, line);
	if (**line != ',')
		ft_error(st, -15);
	(*line)++;
	st->pars.cb = ft_parsearg_ceiling_getvalue(st, line);
	if (!(st->pars.cr >= 0 && st->pars.cr <= 255)
			|| !(st->pars.cg >= 0 && st->pars.cg <= 255)
			|| !(st->pars.cb >= 0 && st->pars.cb <= 255))
		ft_error(st, -16);
	st->pars.clr_c = (st->pars.cr * 65536) + (st->pars.cg * 256) + st->pars.cb;
}

void	ft_parsearg_ceiling(t_st *st, char *line)
{
	if (st->pars.parsedceiling == 1)
		ft_error(st, -10);
	if (st->maps.nbrmaps > 0)
		ft_error(st, -11);
	while (*line == ' ')
		line++;
	if (ft_isdigit(*line) == 1)
		ft_parsearg_ceiling_color(st, &line);
	else if (*line != '\0')
		ft_parsearg_ceiling_text(&line);
	else
		ft_error(st, -12);
	while (*line == ' ')
		line++;
	if (*line != '\0')
		ft_error(st, -13);
	st->pars.parsedceiling = 1;
}
