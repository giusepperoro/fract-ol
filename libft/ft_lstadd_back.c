/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:59:42 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/24 22:19:08 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*help;

	help = *lst;
	if (!help)
	{
		*lst = new;
		return ;
	}
	while (help->next != NULL)
		help = help->next;
	help->next = new;
}
