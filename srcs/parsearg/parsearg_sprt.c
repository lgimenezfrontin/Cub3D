/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_sprt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:04:08 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 13:56:08 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_parsearg_sprt_path(t_st *st, char *line, int i)
{
	if (st->pars.parsedsprt[i] == 1)
		ft_error(st, -10);
	if (st->maps.nbrmaps > 0)
		ft_error(st, -11);
	st->sprt.pathsprt[i] = ft_parsearg_getpath(st, line);
	st->pars.parsedsprt[i] = 1;
}

void	ft_parsearg_sprt(t_st *st, char *line, int i)
{
	if (*line == '_' && *(line + 1) == '2')
		i = 1;
	else if (*line == '_' && *(line + 1) == '3')
		i = 2;
	else if (*line == '_' && *(line + 1) == '4')
		i = 3;
	else if (*line == '_' && *(line + 1) == '5')
		i = 4;
	else if (*line == '_' && *(line + 1) == 'T' && *(line + 2) == 'R'
			&& *(line + 3) == 'A' && *(line + 4) == 'P')
		i = TRAP;
	else if (*line == '_' && *(line + 1) == 'M' && *(line + 2) == 'E'
			&& *(line + 3) == 'D' && *(line + 4) == 'P')
		i = MEDP;
	else if (*line == '_' && *(line + 1) == 'E' && *(line + 2) == 'X'
			&& *(line + 3) == 'I' && *(line + 4) == 'T')
		i = EXIT;
	else
		ft_parsearg_sprt_path(st, line, 0);
	if (i > 0 && i < TRAP)
		ft_parsearg_sprt_path(st, line + 2, i);
	else if (i >= TRAP)
		ft_parsearg_sprt_path(st, line + 5, i);
}
