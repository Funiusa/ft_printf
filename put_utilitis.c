/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utilitis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 20:03:34 by tevelyne          #+#    #+#             */
/*   Updated: 2021/01/15 20:07:37 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_pars *p)
{
	write(1, &c, 1);
	++p->ret_count;
}

void	ft_putstr(char *s, unsigned int len, t_pars *p)
{
	unsigned int		i;

	i = 0;
	if (!s)
		return ;
	while (len > i)
	{
		ft_putchar(s[i], p);
		i++;
	}
}
