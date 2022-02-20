/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:06:35 by tevelyne          #+#    #+#             */
/*   Updated: 2021/01/15 20:15:23 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_initialize(t_pars *p)
{
	p->arg_type = 0;
	p->f_min = 0;
	p->f_zero = 0;
	p->zr = 0;
	p->sp = 0;
	p->width = -1;
	p->pre = -1;
	p->arg_s = NULL;
	p->arg_c = 0;
	p->arg_p = 0;
	p->ret_count = 0;
	p->arg_u = 0;
	p->neg = 0;
}

const char	*ft_t_parser(const char *frmt, t_pars *p, va_list arg)
{
	while (p->arg_type == 0 && *frmt)
	{
		if (*frmt == '-' || *frmt == '0')
			frmt = ft_flags(frmt, p);
		else if (*frmt == '*' || (*frmt > 47 && *frmt < 58))
			frmt = ft_width(frmt, p, arg);
		else if (*frmt == '.')
			frmt = ft_prec(frmt, p, arg);
		else if (*frmt == 'u' || *frmt == 'd' || *frmt == 'i')
			frmt = ft_t_udi(frmt, p, arg);
		else if (*frmt == 's')
			frmt = ft_t_s(frmt, p, arg);
		else if (*frmt == 'c' || *frmt == '%')
			frmt = ft_t_c(frmt, p, arg);
		else if (*frmt == 'x' || *frmt == 'X')
			frmt = ft_t_x(frmt, p, arg);
		else if (*frmt == 'p')
			frmt = ft_t_p(frmt, p, arg);
		else
		{
			ft_putchar(*frmt, p);
			++frmt;
		}
	}
	return (frmt);
}
