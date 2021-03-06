/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:04:39 by cchaumar          #+#    #+#             */
/*   Updated: 2016/10/20 09:33:37 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_generics.h"

size_t	ft_strlen(const char *s)
{
	char *p;

	p = (char *)s;
	if (!s)
		return (0);
	while (*p)
		p++;
	return (p - s);
}
