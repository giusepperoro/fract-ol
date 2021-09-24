/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 22:24:53 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/24 22:28:37 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*help;

	i = 1;
	if (lst == NULL)
		return (0);
	help = lst;
	while (help->next != NULL)
	{
		i++;
		help = help->next;
	}
	return (i);
}
