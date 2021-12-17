/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dcrooijm <dcrooijm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:55:38 by dcrooijm      #+#    #+#                 */
/*   Updated: 2021/11/03 12:38:49 by dcrooijm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	int			i;

	d = dst;
	s = src;
	i = 0;
	if (d > s)
	{
		while (len)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	ft_memcpy(dst, src, len);
	return (dst);
}
