/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:51:39 by tevelyne          #+#    #+#             */
/*   Updated: 2021/01/15 19:54:05 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_format(const char *format, t_pars *p, va_list args)
{
	int		result;

	result = 0;
	while (*format)
	{
		if ('%' == *format)
		{
			ft_initialize(p);
			++format;
			format = ft_t_parser(format, p, args);
			result += p->ret_count;
		}
		if (*format == '\0')
			break ;
		if (*format != '%')
		{
			write(1, format, 1);
			++result;
			++format;
		}
	}
	va_end(args);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_pars		*p;
	int			result;

	p = (t_pars *)malloc(sizeof(t_pars));
	if (!p)
		return (0);
	va_start(args, format);
	result = ft_format(format, p, args);
	free(p);
	p = NULL;
	return (result);
}
