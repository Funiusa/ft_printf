/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:58:58 by tevelyne          #+#    #+#             */
/*   Updated: 2020/11/12 18:05:56 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t num)
{
	if (num == 0)
		return (0);
	while ((*string1 || *string2) && num > 0)
	{
		if (*string1 != *string2)
			return ((unsigned char)*string1 - (unsigned char)*string2);
		string1++;
		string2++;
		num--;
	}
	return (0);
}
