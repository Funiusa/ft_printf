/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 18:29:09 by tevelyne          #+#    #+#             */
/*   Updated: 2020/11/12 18:47:07 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*tmp_dest;
	const char	*tmp_src;
	char		chr;

	tmp_dest = dest;
	chr = c;
	tmp_src = src;
	while (n > 0)
	{
		if (*tmp_src == chr)
		{
			*tmp_dest = *tmp_src;
			return ((void *)tmp_dest + 1);
		}
		*tmp_dest++ = *tmp_src++;
		n--;
	}
	return (0);
}
