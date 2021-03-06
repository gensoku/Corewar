/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bal-khan <bal-khan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 05:42:10 by bal-khan          #+#    #+#             */
/*   Updated: 2016/09/30 22:42:46 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_generics.h"

static size_t	ft_nwords(const char *s, char c)
{
	size_t	nwords;
	size_t	inword;

	inword = 0;
	nwords = 0;
	while (*s != '\0')
	{
		if (inword == 1 && *s == c)
			inword = 0;
		if (inword == 0 && *s != c)
		{
			inword = 1;
			nwords++;
		}
		s++;
	}
	return (nwords);
}

static size_t	ft_getlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	nwords;
	size_t	index;

	index = 0;
	nwords = ft_nwords(s, c);
	if ((tab = ft_memalloc(sizeof(char *) * (nwords + 1))) == NULL)
		return (NULL);
	while (nwords--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[index] = ft_strsub((const char *)s, 0,
		ft_getlen((const char *)s, c));
		if (tab[index] == NULL)
			return (NULL);
		s = s + ft_getlen(s, c);
		index++;
	}
	return (tab);
}
