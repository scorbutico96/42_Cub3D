/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrisari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:58:51 by mcrisari          #+#    #+#             */
/*   Updated: 2021/01/19 14:58:54 by mcrisari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	flag;

	flag = c;
	while (*s)
	{
		if (*s == flag)
			return ((char *)s);
		s++;
	}
	if (!*s && *s == flag)
		return ((char *)s);
	return (0);
}
