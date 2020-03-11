/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:43:57 by lgimenez          #+#    #+#             */
/*   Updated: 2019/10/24 18:49:23 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmplst;

	if (lst && del)
	{
		tmplst = *lst;
		while (tmplst)
		{
			ft_lstdelone(tmplst, del);
			tmplst = tmplst->next;
		}
		*lst = NULL;
	}
}
