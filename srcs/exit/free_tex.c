/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 17:46:45 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/06 19:02:40 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_free_tex_pathtex(t_st *st)
{
	int	i;
	int	j;

	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 4)
		{
			if (st->tex.pathtex[j][i] != NULL)
				free(st->tex.pathtex[j][i]);
			i++;
		}
		j++;
	}
}

void	ft_free_tex(t_st *st)
{
	ft_free_tex_pathtex(st);
}
