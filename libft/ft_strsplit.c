/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 21:45:01 by eserebry          #+#    #+#             */
/*   Updated: 2017/09/29 02:52:52 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_wordcount(char const *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0' && str[i] != c)
			count++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**s2;

	if (!s || !(s2 = (char **)malloc(sizeof(*s2) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_wordcount(s, c))
	{
		k = 0;
		if (!(s2[i] = ft_strnew(ft_wordcount(&s[j], c) + 1)))
			s2 = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			s2[i][k++] = s[j++];
		s2[i][k] = '\0';
	}
	s2[i] = 0;
	return (s2);
}
