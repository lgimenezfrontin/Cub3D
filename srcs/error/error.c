/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 18:36:22 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/11 12:34:26 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

void	ft_error_21to30(int id)
{
	if (id == -21)
		ft_putstr("Couldn't access a visual resource, check their validity\n");
	else if (id == -22)
		ft_putstr("Couldn't create/open the screen.bmp file\n");
	else if (id == -23)
		ft_putstr("Map can't be one dimensional\n");
	else
		ft_putstr("Unknown error\n");
}

void	ft_error_11to20(int id)
{
	if (id == -11)
		ft_putstr("Map must be the last element in the file\n");
	else if (id == -12)
		ft_putstr("Missing information for an element\n");
	else if (id == -13)
		ft_putstr("Invalid information, look for any unnecessary character\n");
	else if (id == -14)
		ft_putstr("Failed malloc\n");
	else if (id == -15)
		ft_putstr("Missing comma between RGB values\n");
	else if (id == -16)
		ft_putstr("Invalid RGB values\n");
	else if (id == -17)
		ft_putstr("Map must be closed\n");
	else if (id == -18)
		ft_putstr("Map must have a start point\n");
	else if (id == -19)
		ft_putstr("Map can only have one start point\n");
	else if (id == -20)
		ft_putstr("Invalid character in map\n");
	else
		ft_putstr("Unknown error\n");
}

void	ft_error_2to10(int id)
{
	if (id == -2)
		ft_putstr("Invalid arguments\n");
	else if (id == -3)
		ft_putstr("Argument file must end by \".cub\"\n");
	else if (id == -4)
		ft_putstr("Can't find/open .cub file\n");
	else if (id == -5)
		ft_putstr(".cub file is not a valid file\n");
	else if (id == -6)
		ft_putstr("Invalid element identifier\n");
	else if (id == -7)
		ft_putstr("Can't have any space before the element identifier\n");
	else if (id == -8)
		ft_putstr("Empty line can't have any space\n");
	else if (id == -9)
		ft_putstr("Map can't be parsed if any element is still missing\n");
	else if (id == -10)
		ft_putstr("Multiple entries for the same element\n");
	else
		ft_putstr("Unknown error\n");
}

void	ft_error(t_st *st, int id)
{
	ft_putstr("Error\n");
	if (id >= -10 && id <= -2)
		ft_error_2to10(id);
	else if (id >= -20 && id <= -11)
		ft_error_11to20(id);
	else if (id >= -30 && id <= -21)
		ft_error_21to30(id);
	else
		ft_putstr("Unknown error\n");
	ft_exit(st, -1);
}
