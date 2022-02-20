/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:48:40 by tevelyne          #+#    #+#             */
/*   Updated: 2020/11/12 18:56:00 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int it;

	it = 0;
	if (n == 0 || (dest == 0 && src == 0))
		return (dest);
	if (dest > src)
	{
		it = (int)n - 1;
		while (it >= 0)
		{
			((char *)dest)[it] = ((char *)src)[it];
			it--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
