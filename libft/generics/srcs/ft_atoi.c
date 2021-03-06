/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 18:09:16 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/23 18:45:41 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_generics.h"

int		ft_atoi(char *str)
{
	int		sign;
	long	number;

	if (!str)
		return (0);
	sign = 1;
	number = 0;
	while (*str && ft_iswhite(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
		number = 10 * number + (*(str++) - '0');
	return ((int)(sign * number));
}
