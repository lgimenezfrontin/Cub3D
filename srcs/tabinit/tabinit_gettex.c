/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabinit_gettex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:58:13 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/04 18:23:12 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_tabinit_gettex_datainit(t_st *st, int j)
{
	void	**tex_ptr;
	int		*tex_bpp;
	int		*tex_sl;
	int		*tex_end;
	int		i;

	tex_ptr = st->tex.tex_ptr[j];
	tex_bpp = st->tex.tex_bpp[j];
	tex_sl = st->tex.tex_sl[j];
	tex_end = st->tex.tex_end[j];
	i = 0;
	while (i < 4)
	{
		if ((st->tex.tex_data[j][i] = (int*)mlx_get_data_addr(tex_ptr[i],
				&tex_bpp[i], &tex_sl[i], &tex_end[i])) == NULL)
			ft_error(st, -21);
		i++;
	}
}

void	ft_tabinit_gettex_ptrinit(t_st *st, int j)
{
	void	**tex_ptr;
	char	**pathtex;
	int		*tex_w;
	int		*tex_h;
	int		i;

	tex_ptr = st->tex.tex_ptr[j];
	pathtex = st->tex.pathtex[j];
	tex_w = st->tex.tex_w[j];
	tex_h = st->tex.tex_h[j];
	i = 0;
	while (i < 4)
	{
		if ((tex_ptr[i] = mlx_xpm_file_to_image(st->mlx.mlx_ptr,
				pathtex[i], &tex_w[i], &tex_h[i])) == NULL)
			ft_error(st, -21);
		i++;
	}
}

void	ft_tabinit_gettex(t_st *st)
{
	if (ft_wallisvalid(st, '1') == 1)
	{
		ft_tabinit_gettex_ptrinit(st, 0);
		ft_tabinit_gettex_datainit(st, 0);
	}
}
