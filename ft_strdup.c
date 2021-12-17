/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dcrooijm <dcrooijm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:55:55 by dcrooijm      #+#    #+#                 */
/*   Updated: 2021/11/04 12:17:23 by dcrooijm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = ft_strlen(s1);
	dst = malloc(i * sizeof(char) + 1);
	if (!dst)
	{
		return (0);
	}
	ft_memcpy(dst, s1, i);
	dst[i] = s1[i];
	return (dst);
}
