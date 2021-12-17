/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dcrooijm <dcrooijm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/03 10:38:30 by dcrooijm      #+#    #+#                 */
/*   Updated: 2021/11/04 12:42:02 by dcrooijm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*firstlst;
	t_list	*newlst;

	firstlst = NULL;
	while (lst)
	{
		newlst = ft_lstnew((*f)(lst->content));
		if (!newlst)
		{
			while (firstlst)
			{
				newlst = firstlst->next;
				(*del)(firstlst->content);
				free(firstlst);
				firstlst = newlst;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&firstlst, newlst);
		lst = lst->next;
	}
	return (firstlst);
}
