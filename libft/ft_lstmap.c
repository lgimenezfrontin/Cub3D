/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgimenez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:49:17 by lgimenez          #+#    #+#             */
/*   Updated: 2019/10/24 19:25:12 by lgimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**anewlst;
	t_list	*newlst;
	t_list	*tmplst;

	if (lst && f && del)
	{
		tmplst = lst;
		newlst = NULL;
		anewlst = &newlst;
		while (tmplst)
		{
			newlst = ft_lstnew(f(tmplst));
			if (!newlst)
			{
				ft_lstclear(anewlst, del);
				return (NULL);
			}
			ft_lstadd_back(anewlst, newlst);
			tmplst = tmplst->next;
		}
		return (*anewlst);
	}
	else
		return (NULL);
}
