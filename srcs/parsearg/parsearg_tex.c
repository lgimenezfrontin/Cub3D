/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_tex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:45:49 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/09 17:48:49 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_parsearg_tex_path(t_st *st, char *line, int j)
{
	int	i;

	i = 0;
	if (*line == 'N' && *(line + 1) == 'O')
		i = 0;
	else if (*line == 'E' && *(line + 1) == 'A')
		i = 1;
	else if (*line == 'S' && *(line + 1) == 'O')
		i = 2;
	else if (*line == 'W' && *(line + 1) == 'E')
		i = 3;
	else
		ft_error(st, -6);
	if (st->pars.parsedtex[j][i] == 1)
		ft_error(st, -10);
	if (st->maps.nbrmaps > 0)
		ft_error(st, -11);
	st->tex.pathtex[j][i] = ft_parsearg_getpath(st, line + 2);
	st->pars.parsedtex[j][i] = 1;
}

void	ft_parsearg_tex(t_st *st, char *line)
{
	int	j;

	j = 0;
	if (*line == '2')
		j = 1;
	else if (*line == '3')
		j = 2;
	else if (*line == '4')
		j = 3;
	else if (*line == '5')
		j = 4;
	else
		ft_error(st, -6);
	if (*(line + 1) != '_')
		ft_error(st, -6);
	ft_parsearg_tex_path(st, line + 2, j);
}
