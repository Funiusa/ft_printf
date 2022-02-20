/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:20:20 by tevelyne          #+#    #+#             */
/*   Updated: 2020/11/13 16:45:03 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	size_s1;
	size_t	size;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	size_s1 = ft_strlen(s1);
	size = size_s1 + ft_strlen(s2);
	new_string = (char *)malloc(sizeof(char) * size + 1);
	if (!new_string)
		return (NULL);
	while (i < size_s1)
	{
		new_string[i] = *s1++;
		i++;
	}
	while (i < size)
	{
		new_string[i] = *s2++;
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
