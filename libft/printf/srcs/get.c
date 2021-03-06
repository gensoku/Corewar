/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchaumar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 04:48:08 by cchaumar          #+#    #+#             */
/*   Updated: 2017/02/05 23:25:14 by cchaumar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		get_decimal(t_field *f, t_data *d)
{
	static uint64_t	(*cast[8])(uint64_t, int *) = {cast_uint, cast_int,
		cast_uchar, cast_char, cast_ushort, cast_short, cast_uint64,
		cast_int64};
	uint64_t		n;
	int				sign;

	n = va_arg(d->args, uint64_t);
	n = cast[!(f->bools & UNSIGNED) + 2 * MIN(f->mods, 3)](n, &sign);
	itoa64base(n, !!(f->bools & BASE8) * 8 + !!(f->bools & BASE10) * 10
		+ !!(f->bools & BASE16) * 16, f);
	CHECK(f->flag, n == 0 && (f->bools & BASE16), 0xFF ^ ALT);
	f->sign = sign * !!(f->bools & DS);
	p_format(f, d);
	free(f->buff);
}

void		get_float(t_field *f, t_data *d)
{
	(void)d;
	f->size = 0;
}

void		p_get_string(t_field *f, t_data *d)
{
	int	flag;

	flag = 0;
	if (f->mods & L_M)
		f->buff = wstr(va_arg(d->args, unsigned int *), f);
	else
	{
		f->buff = va_arg(d->args, char *);
		flag = !f->buff;
		if (f->buff == NULL)
			f->buff = ft_strndup("(null)", f->prec == -1 ? 6 :
			f->prec);
		f->size = f->prec == -1 ? ft_strlen(f->buff) :
			MIN(ft_strlen(f->buff), (size_t)f->prec);
	}
	p_format(f, d);
	if ((f->mods & L_M) | flag)
		free(f->buff);
}

void		get_char(t_field *f, t_data *d)
{
	t_wchar		c;

	c.n = va_arg(d->args, unsigned int);
	f->size = c.n ? get_wchar(&c.n) : 1;
	f->buff = ft_memalloc(f->size);
	ft_memcpy(f->buff, c.c, f->size);
	p_format(f, d);
	free(f->buff);
}

void		get_pointer(t_field *f, t_data *d)
{
	uint64_t	t;

	t = va_arg(d->args, uint64_t);
	itoa64base(t, 16, f);
	p_format(f, d);
	free(f->buff);
}
