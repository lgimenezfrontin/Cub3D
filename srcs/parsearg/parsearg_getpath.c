/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsearg_getpath.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:37:53 by lgimenez          #+#    #+#             */
/*   Updated: 2020/03/09 17:51:00 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/cub3d.h"

char	*ft_parsearg_getpath(t_st *st, char *line)
{
	char	*str;
	int		i;

	str = NULL;
	while (*line == ' ')
		line++;
	if (*line == '\0')
		ft_error(st, -12);
	if ((str = ft_strdup(line)) == NULL)
		ft_error(st, -14);
	i = 0;
	while (*(str + i) != ' ' && *(str + i) != '\0')
		i++;
	*(str + i) = '\0';
	while (*line != ' ' && *line != '\0')
		line++;
	while (*line == ' ')
		line++;
	if (*line != '\0')
		ft_error(st, -13);
	return (str);
}
