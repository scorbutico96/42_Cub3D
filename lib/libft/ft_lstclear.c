/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcrisari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:13:05 by mcrisari          #+#    #+#             */
/*   Updated: 2021/01/29 13:14:13 by mcrisari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*tmp;

	if (*lst)
	{
		ptr = *lst;
		while (ptr)
		{
			tmp = ptr;
			if (del)
				(del)(ptr->content);
			ptr = ptr->next;
			free(tmp);
		}
	}
	*lst = NULL;
}
