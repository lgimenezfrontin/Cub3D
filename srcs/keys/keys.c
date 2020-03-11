/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:59:24 by lgimenez          #+#    #+#             */
/*   Updated: 2020/02/29 18:19:17 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_keys(t_st *st)
{
	if (st->keys.w == 1)
		ft_keys_movefwd(st);
	if (st->keys.s == 1)
		ft_keys_movebwd(st);
	if (st->keys.a == 1)
		ft_keys_moveleft(st);
	if (st->keys.d == 1)
		ft_keys_moveright(st);
	if (st->keys.left == 1)
		ft_keys_rotationleft(st);
	if (st->keys.right == 1)
		ft_keys_rotationright(st);
	if (st->keys.plus == 1 && st->keys.keepplus == 0)
		ft_keys_lvlplus(st);
	if (st->keys.minus == 1 && st->keys.keepminus == 0)
		ft_keys_lvlminus(st);
	if (st->keys.esc == 1)
		ft_exit(st, 0);
}
