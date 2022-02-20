/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:29:48 by tevelyne          #+#    #+#             */
/*   Updated: 2021/01/13 14:44:55 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size(long unsigned int num)
{
	int		size;

	size = 0;
	if (num == 0)
		size++;
	while (num > 0)
	{
		num /= 16;
		size++;
	}
	return (size);
}

char	*ft_hex(long unsigned int num, char h)
{
	char	*hex;
	int		size;
	char	*hexnum;

	hex = h == 'x' ? "0123456789abcdef" : "0123456789ABCDEF";
	size = ft_size(num);
	hexnum = (char *)malloc(sizeof(char) * size + 1);
	if (!hexnum)
		return (NULL);
	hexnum[size] = '\0';
	while (size > 0)
	{
		hexnum[size - 1] = hex[num % 16];
		num /= 16;
		size--;
	}
	return (hexnum);
}
