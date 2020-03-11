/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_writebmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:44:35 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 12:44:39 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_save_writebmp_halfint(int fd, int val)
{
	char ptr;

	ptr = val & 0xff;
	write(fd, &ptr, 1);
	ptr = (val >> 8) & 0xff;
	write(fd, &ptr, 1);
}

void	ft_save_writebmp_int(int fd, int val)
{
	ft_save_writebmp_halfint(fd, val);
	ft_save_writebmp_halfint(fd, val >> 16);
}

void	ft_save_writebmp_color(int fd, int color)
{
	char ptr;

	ft_save_writebmp_halfint(fd, color);
	ptr = color >> 16 & 0xff;
	write(fd, &ptr, 1);
}

void	ft_save_writebmp(t_st *st, int fd, int lsize)
{
	write(fd, "BM", 2);
	ft_save_writebmp_int(fd, 54 + (3 * (st->win.winw + lsize)
		* st->win.winh % 4));
	ft_save_writebmp_int(fd, 0);
	ft_save_writebmp_int(fd, 54);
	ft_save_writebmp_int(fd, 40);
	ft_save_writebmp_int(fd, st->win.winw);
	ft_save_writebmp_int(fd, st->win.winh);
	ft_save_writebmp_halfint(fd, 1);
	ft_save_writebmp_halfint(fd, 24);
	ft_save_writebmp_int(fd, 0);
	ft_save_writebmp_int(fd, 0);
	ft_save_writebmp_int(fd, 6400);
	ft_save_writebmp_int(fd, 6400);
	ft_save_writebmp_int(fd, 0);
	ft_save_writebmp_int(fd, 0);
}
