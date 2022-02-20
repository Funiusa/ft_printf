/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_diux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:43:15 by tevelyne          #+#    #+#             */
/*   Updated: 2021/01/15 19:57:13 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_locate(char *str, t_pars *p)
{
	if (p->f_min)
		ft_min_mod(str, p);
	else
		ft_mod(str, p);
}

void	ft_min_width(t_pars *p, int lens)
{
	if (p->pre != -1 && p->f_zero && p->pre > lens)
		p->zr = p->pre - lens;
	else if (p->pre == -1 && p->f_zero)
		p->zr = p->width - lens;
	else if (p->pre != -1 && !p->f_zero)
		p->zr = p->pre - lens;
	if (p->zr < 0)
		p->zr = 0;
	p->sp = p->width - lens - p->zr;
	if (p->neg && !p->sp && p->width > p->pre)
		--p->zr;
	if (p->neg)
		--p->sp;
}

void	ft_zero_flag(t_pars *p, int lens)
{
	if (p->pre > lens)
	{
		if (p->neg)
			ft_putchar('-', p);
		while (p->zr--)
			ft_putchar('0', p);
	}
	else if (p->width <= lens)
	{
		if (p->neg)
			ft_putchar('-', p);
	}
	else if (p->width > lens)
	{
		while (p->sp--)
			ft_putchar(' ', p);
		if (p->neg)
			ft_putchar('-', p);
	}
}

void	ft_neg_pos(t_pars *p, int lens)
{
	if (p->f_zero && !p->neg && p->pre == -1 && p->width > lens)
		while (p->zr--)
			ft_putchar('0', p);
	else if (p->f_zero && p->neg && p->pre == -1
	&& p->width > lens)
	{
		ft_putchar('-', p);
		while (p->zr--)
			ft_putchar('0', p);
	}
}

void	ft_mod(char *str, t_pars *p)
{
	int lens;

	lens = ft_strlen(str);
	ft_min_width(p, lens);
	if (p->f_zero && p->pre == -1 && p->width > lens)
		ft_neg_pos(p, lens);
	else if (p->pre != -1 && p->width > lens
	&& !p->neg && p->width > p->pre)
	{
		while (p->sp--)
			ft_putchar(' ', p);
		while (p->zr--)
			ft_putchar('0', p);
	}
	else if (p->width > lens && p->neg && p->width > p->pre)
	{
		while (p->sp--)
			ft_putchar(' ', p);
		ft_putchar('-', p);
		while (p->zr--)
			ft_putchar('0', p);
	}
	else if (p->pre > lens || p->width <= lens || p->width > lens)
		ft_zero_flag(p, lens);
	ft_putstr(str, ft_strlen(str), p);
}
