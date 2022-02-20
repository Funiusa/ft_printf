/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:26:31 by tevelyne          #+#    #+#             */
/*   Updated: 2021/01/15 20:00:16 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_u_type(t_pars *p, va_list args)
{
	p->arg_u = va_arg(args, unsigned int);
	if (p->arg_u == 0 && p->pre == 0)
		p->arg_s = ft_strdup("");
	else
		p->arg_s = ft_itoa_ft(p->arg_u);
}

const char	*ft_t_udi(const char *format, t_pars *p, va_list args)
{
	long int	n;

	if (*format == 'u')
		ft_u_type(p, args);
	else if (*format == 'd' || *format == 'i')
	{
		n = va_arg(args, int);
		if (n < 0)
		{
			n *= -1;
			p->neg = 1;
		}
		if (n == 0 && p->pre == 0)
			p->arg_s = ft_strdup("");
		else
			p->arg_s = ft_itoa_ft(n);
	}
	ft_locate(p->arg_s, p);
	free(p->arg_s);
	p->arg_type = 1;
	return (++format);
}

const char	*ft_t_x(const char *format, t_pars *p, va_list args)
{
	unsigned int tmp;

	p->arg_type = 1;
	tmp = va_arg(args, unsigned int);
	if (tmp == 0 && p->pre == 0)
		p->arg_s = ft_strdup("");
	else
		p->arg_s = ft_hex(tmp, *format);
	ft_locate(p->arg_s, p);
	free(p->arg_s);
	return (++format);
}

const char	*ft_t_p(const char *format, t_pars *p, va_list args)
{
	p->arg_type = 1;
	p->arg_p = va_arg(args, long int);
	if (p->arg_p == 0 && p->pre != -1)
	{
		p->arg_s = "";
		ft_p_locate(p->arg_s, p);
	}
	else
	{
		p->arg_s = ft_hex(p->arg_p, 'x');
		ft_p_locate(p->arg_s, p);
		free(p->arg_s);
	}
	return (++format);
}
