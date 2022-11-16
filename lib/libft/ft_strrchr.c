/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrisari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:03:37 by mcrisari          #+#    #+#             */
/*   Updated: 2021/01/21 18:24:32 by mcrisari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	flag;
	int		len;

	flag = c;
	len = ft_strlen(s);
	s = &s[len];
	if (*s == flag)
		return ((char *)s);
	while (len-- >= 0)
	{
		if (*s == flag)
			return ((char *)s);
		s--;
	}
	return (0);
}
