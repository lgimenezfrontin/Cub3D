/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_keyrelease.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:29:03 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/29 17:48:07 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_keys_keyrelease_various(int key, t_st *st)
{
	if (key == 65451)
	{
		st->keys.plus = 0;
		st->keys.keepplus = 0;
	}
	if (key == 65453)
	{
		st->keys.minus = 0;
		st->keys.keepminus = 0;
	}
	if (key == 65307)
		st->keys.esc = 0;
}

void	ft_keys_keyrelease_directions(int key, t_st *st)
{
	if (key == 122)
		st->keys.w = 0;
	if (key == 113)
		st->keys.a = 0;
	if (key == 115)
		st->keys.s = 0;
	if (key == 100)
		st->keys.d = 0;
	if (key == 65362)
		st->keys.up = 0;
	if (key == 65364)
		st->keys.down = 0;
	if (key == 65361)
		st->keys.left = 0;
	if (key == 65363)
		st->keys.right = 0;
}

int		ft_keys_keyrelease(int key, t_st *st)
{
	ft_keys_keyrelease_directions(key, st);
	ft_keys_keyrelease_various(key, st);
	return (0);
}
