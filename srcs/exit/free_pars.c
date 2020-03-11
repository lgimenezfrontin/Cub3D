/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:13:37 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 12:13:42 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_free_pars(t_st *st)
{
	if (st->pars.line != NULL)
		free(st->pars.line);
	if (st->pars.strmap != NULL)
		free(st->pars.strmap);
}
