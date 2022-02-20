/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:41:14 by tevelyne          #+#    #+#             */
/*   Updated: 2020/11/13 16:41:15 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	substring = (char *)malloc(sizeof(char) * len + 1);
	if (!substring)
		return (NULL);
	if ((size_t)ft_strlen((char *)s) > start)
		while (len > 0)
		{
			substring[i] = s[start + i];
			i++;
			len--;
		}
	substring[i] = '\0';
	return (substring);
}
