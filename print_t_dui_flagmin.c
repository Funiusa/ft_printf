/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_dui_flagmin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:43:15 by tevelyne          #+#    #+#             */
/*   Updated: 2021/01/15 20:01:47 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ion(t_pars *p, char *str, int lens)
{
	if ((!p->neg && p->pre > lens && p->width < p->pre)
	|| (p->width > lens && p->width > p->pre))
	{
		while (p->zr--)
			ft_putchar('0', p);
		ft_putstr(str, ft_strlen(str), p);
		while (p->sp--)
			ft_putchar(' ', p);
	}
	else if ((p->pre > lens && p->width < lens)
	|| (p->width >= lens && p->pre > lens))
	{
		while (p->zr--)
			ft_putchar('0', p);
		ft_putstr(str, ft_strlen(str), p);
	}
	else if (p->width > lens && p->pre == -1)
	{
		ft_putstr(str, ft_strlen(str), p);
		while (p->sp--)
			ft_putchar(' ', p);
	}
	else
		ft_putstr(str, ft_strlen(str), p);
}

int		ft_s_width(char *str, t_pars *p)
{
	int lens;

	lens = ft_strlen(str);
	if (p->pre != -1 && !p->f_zero)
		p->zr = p->pre - lens;
	if (p->pre != -1 && p->f_zero)
		p->zr = p->pre - lens;
	if (p->zr < 0)
		p->zr = 0;
	p->sp = p->width - lens - p->zr;
	if (p->sp < 0)
		p->sp = 0;
	if (p->neg)
		--p->sp;
	return (lens);
}

void	ft_min_mod(char *str, t_pars *p)
{
	int lens;

	lens = ft_s_width(str, p);
	if (p->neg)
		ft_putchar('-', p);
	if (p->pre == -1 || p->width < lens
	|| p->neg || p->width < p->pre)
		ft_ion(p, str, lens);
	else
	{
		while (p->zr--)
			ft_putchar('0', p);
		ft_putstr(str, ft_strlen(str), p);
		while (p->sp--)
			ft_putchar(' ', p);
	}
}
