/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:42:10 by tevelyne          #+#    #+#             */
/*   Updated: 2021/01/15 21:03:41 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p_locate(char *str, t_pars *p)
{
	if (p->f_min)
		ft_p_min_mod(str, p);
	else
		ft_p_mod(str, p);
}

void	ft_p_min_width(t_pars *p, char *str)
{
	int lens;

	lens = ft_strlen(str);
	if (p->pre > lens && !p->f_zero)
		p->zr = p->pre - lens;
	if (p->pre > lens && p->f_zero)
		p->zr = p->pre - lens;
	if (p->zr < 0)
		p->zr = 0;
	p->sp = p->width - lens - p->zr - 2;
	if (p->sp < 0)
		p->sp = 0;
	ft_putstr("0x", 2, p);
	if ((p->pre == -1 && p->f_zero && p->width > lens)
		|| (p->width < lens && p->pre > lens))
	{
		while (p->zr--)
			ft_putchar('0', p);
		ft_putstr(str, ft_strlen(str), p);
	}
}

void	ft_p_min_mod(char *str, t_pars *p)
{
	int lens;

	lens = ft_strlen(str);
	ft_p_min_width(p, str);
	if ((p->pre == -1 && p->f_zero && p->width > lens)
		|| (p->width < lens && p->pre > lens))
		ft_p_min_width(p, str);
	else if (p->width > lens && p->width > p->pre)
	{
		while (p->zr--)
			ft_putchar('0', p);
		ft_putstr(str, ft_strlen(str), p);
		while (p->sp--)
			ft_putchar(' ', p);
	}
	else if (p->width >= lens && p->pre == -1)
	{
		ft_putstr(str, ft_strlen(str), p);
		while (p->sp--)
			ft_putchar(' ', p);
	}
	else if (p->width < lens && p->pre < lens)
		ft_putstr(str, ft_strlen(str), p);
	else
		ft_putchar('0', p);
}

void	ft_p_width(t_pars *p, char *str)
{
	int lens;

	lens = ft_strlen(str);
	if (p->pre > lens && !p->f_zero)
		p->zr = p->pre - lens;
	if (p->pre != -1 && p->f_zero)
		p->zr = p->pre - lens;
	if (p->pre == -1 && p->f_zero)
		p->zr = p->width - lens - 2;
	if (p->zr < 0)
		p->zr = 0;
	p->sp = p->width - lens - p->zr - 2;
	if (p->sp < 0)
		p->sp = 0;
	if ((p->pre == -1 && p->f_zero && p->width > lens)
		|| (p->pre != -1 && p->pre > lens))
	{
		ft_putstr("0x", 2, p);
		while (p->zr--)
			ft_putchar('0', p);
	}
}

void	ft_p_mod(char *str, t_pars *p)
{
	int lens;

	lens = ft_strlen(str);
	ft_p_width(p, str);
	if (p->pre != -1 && p->width > lens && p->width > p->pre)
	{
		while (p->sp--)
			ft_putchar(' ', p);
		ft_putstr("0x", 2, p);
		while (p->zr--)
			ft_putchar('0', p);
	}
	else if (p->width <= lens)
		ft_putstr("0x", 2, p);
	else if (p->width > lens)
	{
		while (p->sp--)
			ft_putchar(' ', p);
		ft_putstr("0x", 2, p);
	}
	ft_putstr(str, ft_strlen(str), p);
}
