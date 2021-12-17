/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dcrooijm <dcrooijm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/02 14:22:40 by dcrooijm      #+#    #+#                 */
/*   Updated: 2021/11/04 12:20:08 by dcrooijm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = (*lst);
	if (!(*lst))
		return ;
	while ((*lst) != NULL)
	{
		(*lst) = (*lst)->next;
		del(temp->content);
		free (temp);
		temp = (*lst);
	}
	(*lst) = NULL;
}
