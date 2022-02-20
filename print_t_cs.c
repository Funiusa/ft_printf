/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:19:32 by tevelyne          #+#    #+#             */
/*   Updated: 2021/01/15 20:12:20 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_str_locate(t_pars *p)
{
	int	lens;

	if (p->arg_s == NULL)
		p->arg_s = "(null)";
	lens = ft_strlen(p->arg_s);
	if (p->pre != -1 && p->pre < lens)
		lens = p->pre;
	if (p->width && (p->width > lens) && !p->f_min)
		while (lens < p->width--)
			ft_putchar(' ', p);
	ft_putstr(p->arg_s, lens, p);
	if (p->width && (p->width > lens) && p->f_min)
		while (lens < p->width--)
			ft_putchar(' ', p);
}

void	ft_c_locate(char *str, t_pars *p)
{
	if (p->f_min)
	{
		ft_putstr(str, 1, p);
		if (1 < p->width)
			while (1 < p->width--)
				ft_putchar(' ', p);
	}
	else
	{
		if (p->f_zero)
			while (1 < p->width--)
				ft_putchar('0', p);
		while (1 < p->width)
		{
			ft_putchar(' ', p);
			p->width--;
		}
		ft_putstr(str, 1, p);
	}
}
