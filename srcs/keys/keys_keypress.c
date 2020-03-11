/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_keypress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:28:12 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/07 16:37:50 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_keys_keypress_various(int key, t_st *st)
{
	if (key == 69)
		st->keys.plus = 1;
	if (key == 78)
		st->keys.minus = 1;
	if (key == 53)
		st->keys.esc = 1;
}

void	ft_keys_keypress_directions(int key, t_st *st)
{
	if (key == 13)
		st->keys.w = 1;
	if (key == 0)
		st->keys.a = 1;
	if (key == 1)
		st->keys.s = 1;
	if (key == 2)
		st->keys.d = 1;
	if (key == 126)
		st->keys.up = 1;
	if (key == 125)
		st->keys.down = 1;
	if (key == 123)
		st->keys.left = 1;
	if (key == 124)
		st->keys.right = 1;
}

int		ft_keys_keypress(int key, t_st *st)
{
	ft_keys_keypress_directions(key, st);
	ft_keys_keypress_various(key, st);
	return (0);
}
