/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dcrooijm <dcrooijm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:56:05 by dcrooijm      #+#    #+#                 */
/*   Updated: 2021/12/09 16:06:17 by dcrooijm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*rtn;

	if (!s || !f)
		return (NULL);
	i = 0;
	rtn = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!rtn)
		return (NULL);
	while (s[i])
	{
		rtn[i] = (*f)(i, s[i]);
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
