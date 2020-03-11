/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wallisvalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:17:32 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/04 18:15:32 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

int		ft_wallisvalid(t_st *st, int j)
{
	int	i;

	if (j == '1')
		j = 0;
	else
		return (0);
	i = 0;
	while (i < 4)
	{
		if (st->tex.pathtex[j][i] == NULL)
			return (0);
		i++;
	}
	return (1);
}
