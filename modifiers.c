/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:57:36 by tevelyne          #+#    #+#             */
/*   Updated: 2021/01/15 20:14:47 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_flags(const char *format, t_pars *p)
{
	if (*format == '-')
		p->f_min = 1;
	else if (*format == '0')
		p->f_zero = 1;
	return (++format);
}

const char	*ft_width(const char *format, t_pars *p, va_list args)
{
	if (*format == '*')
	{
		p->width = va_arg(args, int);
		if (p->width < 0)
		{
			p->f_min = 1;
			p->width *= -1;
		}
		++format;
	}
	if (*format > 47 && *format < 58)
		p->width = ft_atoi(format);
	while (*format > 47 && *format < 58)
		++format;
	return (format);
}

void		ft_negative_precision(const char *format, t_pars *p)
{
	while (*format > 47 && *format < 58)
	{
		p->pre = p->pre * 10 + (*format - '0');
		++format;
	}
	p->pre = -1;
}

const char	*ft_prec(const char *format, t_pars *p, va_list args)
{
	++format;
	p->pre = 0;
	if (*format == '*')
	{
		p->pre = va_arg(args, int);
		if (p->pre < 0)
		{
			p->pre = -1;
			return (++format);
		}
		++format;
	}
	if (*format == '-')
	{
		++format;
		ft_negative_precision(format, p);
	}
	if (*format > 47 && *format < 58)
		p->pre = ft_atoi(format);
	while (*format > 47 && *format < 58)
		++format;
	return (format);
}
