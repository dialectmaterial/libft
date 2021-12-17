/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dcrooijm <dcrooijm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/28 13:55:52 by dcrooijm      #+#    #+#                 */
/*   Updated: 2021/11/23 18:22:07 by dcrooijm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_count(const char *s, char c)
{
	int	i;
	int	strc;

	i = 0;
	strc = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			strc++;
		while (s[i] != c && s[i])
			i++;
	}
	return (strc);
}

static char	*add_str(char const *s, char c)
{
	int		i;
	char	*split_str;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	split_str = (char *)malloc(sizeof(char) * i + 1);
	if (!split_str)
		return (NULL);
	ft_strlcpy(split_str, s, i + 1);
	return (split_str);
}

static char	**free_rtn(char **rtn, int i)
{
	while (i)
	{
		free (rtn[i]);
		i--;
	}
	free (rtn);
	return (0);
}

char	**ft_split(const char *s, const char c)
{
	char	**rtn;
	int		i;
	int		strc;

	if (!s)
		return (NULL);
	strc = str_count(s, c);
	rtn = (char **)malloc(sizeof(char *) * (strc + 1));
	if (!rtn)
		return (NULL);
	i = 0;
	while (i < strc)
	{
		while (*s == c)
			s++;
		rtn[i] = add_str(s, c);
		if (!rtn[i])
			return (free_rtn(rtn, i));
		s = s + ft_strlen(rtn[i]);
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
