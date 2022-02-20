/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tevelyne <tevelyne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:04:20 by tevelyne          #+#    #+#             */
/*   Updated: 2020/11/12 19:10:12 by tevelyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *tmp_str;

	tmp_str = NULL;
	while (*str)
	{
		if (*str == ch)
			tmp_str = (char *)(str);
		str++;
	}
	if (!ch)
		return ((char *)(str));
	return (tmp_str);
}
