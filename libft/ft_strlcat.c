/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:16:03 by tevelyne          #+#    #+#             */
/*   Updated: 2020/11/12 18:07:56 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t srclen;
	size_t count;
	size_t dstlen;

	count = 0;
	srclen = ft_strlen(src);
	while (count < size && *dst)
	{
		count++;
		dst++;
	}
	dstlen = count;
	if (size != 0)
		while (*src && count < size - 1)
		{
			*dst++ = *src++;
			count++;
		}
	if (count < size)
		*dst = '\0';
	return (srclen + dstlen);
}
