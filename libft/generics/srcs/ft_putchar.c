/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <cchaumar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:58:58 by cchaumar          #+#    #+#             */
/*   Updated: 2016/01/22 21:02:07 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_generics.h"

void	ft_putchar(char c)
{
	ft_putchar_fd(c, 1);
}
