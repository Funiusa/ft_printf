/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 20:16:47 by tevelyne          #+#    #+#             */
/*   Updated: 2020/11/12 19:03:22 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	count;
	char	*tmp_s;

	tmp_s = (char *)s;
	count = 0;
	while (count < n)
	{
		if (tmp_s[count] == c)
			return ((void *)(tmp_s + count));
		count++;
	}
	return (NULL);
}
