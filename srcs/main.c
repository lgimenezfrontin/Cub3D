/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:07:26 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/09 16:08:57 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int		ft_closewin(t_st *st)
{
	ft_exit(st, 0);
	return (0);
}

int		ft_loophook(t_st *st)
{
	ft_keys(st);
	ft_rayc(st);
	return (0);
}

int		main(int argc, char **argv)
{
	t_st	st;

	ft_varinit(&st);
	if (argc == 3)
		ft_save(&st, argv);
	else if (argc == 2)
	{
		st.spd.movespeed = 0.07;
		st.spd.rotspeed = 0.05;
		st.mlx.mlx_ptr = mlx_init();
		ft_parsearg(&st, argv[1]);
		ft_tabinit(&st);
		st.mlx.win_ptr = mlx_new_window(st.mlx.mlx_ptr,
			st.win.winw, st.win.winh, "Cub3D");
		ft_lvlinit(&st);
		mlx_hook(st.mlx.win_ptr, 2, (1L << 0), ft_keys_keypress, &st);
		mlx_hook(st.mlx.win_ptr, 3, (1L << 1), ft_keys_keyrelease, &st);
		mlx_hook(st.mlx.win_ptr, 17, 0, ft_closewin, &st);
		mlx_loop_hook(st.mlx.mlx_ptr, ft_loophook, &st);
		mlx_loop(st.mlx.mlx_ptr);
	}
	else
		ft_error(&st, -2);
	return (0);
}
