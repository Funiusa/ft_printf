/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:44:05 by tevelyne          #+#    #+#             */
/*   Updated: 2020/11/13 16:46:22 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	size;
	char			*new_str;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	new_str = (char *)malloc(sizeof(char) * size + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_str[i] = f(i, *s);
		s++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
