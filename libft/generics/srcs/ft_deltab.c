/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 00:34:44 by cchaumar          #+#    #+#             */
/*   Updated: 2016/02/27 00:36:22 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_generics.h"

void	ft_deltab(char **tab)
{
	char **cpy;

	cpy = tab;
	while (*tab)
		ft_memdel((void **)tab++);
	ft_memdel((void **)&cpy);
}
