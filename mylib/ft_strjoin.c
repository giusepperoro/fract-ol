/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 22:43:50 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/11 12:27:03 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	size_t	i;
	size_t	sum;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	sum = ft_strlen(s1) + ft_strlen(s2);
	buff = (char *)malloc(sum + 1);
	if (buff == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		*(buff++) = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		*(buff++) = s2[i];
		i++;
	}
	*buff = '\0';
	return (buff - sum);
}
