/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_sc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:29:44 by tevelyne          #+#    #+#             */
/*   Updated: 2021/01/15 20:00:27 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_t_s(const char *format, t_pars *p, va_list args)
{
	p->arg_type = 1;
	p->arg_s = va_arg(args, char *);
	ft_str_locate(p);
	return (++format);
}

const char	*ft_t_c(const char *format, t_pars *p, va_list args)
{
	char	str[2];

	p->arg_type = 1;
	p->arg_c = *format == '%' ? '%' : va_arg(args, int);
	str[0] = (char)p->arg_c;
	str[1] = '\0';
	ft_c_locate(str, p);
	return (++format);
}
