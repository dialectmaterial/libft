/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dcrooijm <dcrooijm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:56:14 by dcrooijm      #+#    #+#                 */
/*   Updated: 2021/11/10 13:40:03 by dcrooijm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_in_s1(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (set_in_s1(s1[i], (char *) set))
		i++;
	j = ft_strlen(s1);
	while (j > i && set_in_s1(s1[j - 1], (char *) set))
		j--;
	ptr = (char *) malloc(sizeof(*s1) * (j - i + 1));
	if (!ptr)
		return (NULL);
	k = 0;
	while (i < j)
	{
		ptr[k] = s1[i];
		k++;
		i++;
	}
	ptr[k] = '\0';
	return (ptr);
}
