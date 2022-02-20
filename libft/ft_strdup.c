/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:43:28 by tevelyne          #+#    #+#             */
/*   Updated: 2020/11/13 17:13:37 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		size;
	char	*mass;

	size = 0;
	while (src[size] != '\0')
		size++;
	mass = (char *)malloc(sizeof(char) * (size + 1));
	if (!mass)
		return (NULL);
	size = 0;
	while (src[size] != '\0')
	{
		mass[size] = src[size];
		size++;
	}
	mass[size] = '\0';
	return (mass);
}
