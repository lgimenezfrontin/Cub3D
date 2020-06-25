/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:44:27 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 12:44:31 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_save_writeend(int fd, int val)
{
	while (val)
	{
		write(fd, "\0", 1);
		val--;
	}
}

void	ft_save_writedata(t_st *st, int fd)
{
	int				i;
	int				j;
	unsigned int	color;
	int				r;

	r = (st->win.winw * 3) % 4;
	i = st->win.winh - 1;
	while (i >= 0)
	{
		j = -1;
		while (++j < st->win.winw)
		{
			color = st->mlx.img_data[(st->win.winw * i) + j];
			ft_save_writebmp_color(fd, color);
			if (r)
				ft_save_writeend(fd, 4 - r);
		}
		i--;
	}
}

void	ft_save_screenshot(t_st *st)
{
	int fd;
	int lsize;

	lsize = (4 - (st->win.winw * 3) % 4) % 4;
	if (!(fd = open("screen.bmp", O_WRONLY
					| O_CREAT, 0666)))
		ft_error(st, -22);
	ft_save_writebmp(st, fd, lsize);
	ft_save_writedata(st, fd);
	close(fd);
}

void	ft_save(t_st *st, char **argv)
{
	if (ft_strcmp(argv[2], "--save") != 0)
		ft_error(st, -2);
	else
	{
		st->mlx.mlx_ptr = mlx_init();
		mlx_get_screen_size(st->mlx.mlx_ptr, &st->win.maxw, &st->win.maxh);
		ft_parsearg(st, argv[1]);
		ft_tabinit(st);
		st->mlx.win_ptr = mlx_new_window(st->mlx.mlx_ptr,
			st->win.winw, st->win.winh, "Cub3D");
		ft_lvlinit(st);
		ft_rayc(st, 1);
		ft_save_screenshot(st);
	}
}
